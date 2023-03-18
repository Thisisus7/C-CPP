
#include <wb.h>
#define TILE_WIDTH 8

// Compute C = A * B
__global__ void CrossMax(int *Data, int *OutData, int size){
  __shared__ float t_r[TILE_WIDTH][TILE_WIDTH];
  __shared__ float t_c[TILE_WIDTH][TILE_WIDTH];
  int bx = blockIdx.x; int by = blockIdx.y;
  int tx = threadIdx.x; int ty = threadIdx.y;
  int Row = by * TILE_WIDTH + ty;
  int Col = bx * TILE_WIDTH + tx;
  float temp = 0;

  for(int i = 0; i < ceil(size/(TILE_WIDTH*1.0)); i++)
  {
    if (Row < size && (i * TILE_WIDTH + tx) < size)
      t_r[ty][tx] = Data[Row * size + i * TILE_WIDTH + tx];
    else
      t_r[ty][tx] = 0;
    if (Col < size && (i * TILE_WIDTH + ty) < size)
      t_c[ty][tx] = Data[size * (i * TILE_WIDTH + ty) + Col];
    else
      t_c[ty][tx] = 0;
    __syncthreads();

    if (Row < size && Col < size)
      for (int j = 0; j< TILE_WIDTH; j++)
        Pvalue = max(t_r[ty][j], t_c[j][tx]);
    __syncthreads();

  }
  if (Row < size && Col < size)
    OutData[Row * size + Col] = temp;
}

int main(int argc, char **argv) {
  wbArg_t args;
  int *h_Data;
  int *h_OutData;
  int *d_Data;
  int *d_OutData;
  int size;

  args = wbArg_read(argc, argv);

  h_Data = (float *)wbImport(wbArg_getInputFile(args, 0), &size,
                            &size);

  // Allocate the hostC matrix
  h_OutData = (float *)malloc(size * size * sizeof(float));

  // Allocate GPU memory here
  cudaMalloc((void **)&d_Data, sizeof(float) * size * size);
  cudaMalloc((void **)&d_OutData, sizeof(float) * size * size);

  cudaMemcpy(d_Data, h_Data, sizeof(float) * size * size, cudaMemcpyHostToDevice);

  dim3 DimGrid(ceil((size*1.0)/TILE_WIDTH), ceil((size*1.0)/TILE_WIDTH), 1);
  dim3 DimBlock(TILE_WIDTH, TILE_WIDTH, 1);

  // Launch the GPU Kernel here
  CrossMax<<<DimGrid, DimBlock>>>(d_Data, d_OutData, size);
  cudaDeviceSynchronize();

  //Copy the GPU memory back to the CPU here
  cudaMemcpy(h_Data, d_OutData, sizeof(float) * size * size, cudaMemcpyDeviceToHost);

  // GPU
  cudaFree(d_Data);
  cudaFree(d_OutData);
  // host
  free(h_Data);
  free(h_OutData);

  return 0;
}
