#include <torch/all.h>
#include <torch/python.h>
#include <c10/cuda/CUDAGuard.h>

void vecquant2matmul_cuda(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
); 

void vecquant2matmul(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
) {
  const at::cuda::OptionalCUDAGuard device_guard(device_of(vec));
  vecquant2matmul_cuda(vec, mat, mul, scales, zeros);
}

void vecquant3matmul_cuda(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
); 

void vecquant3matmul(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
) {
  const at::cuda::OptionalCUDAGuard device_guard(device_of(vec));
  vecquant3matmul_cuda(vec, mat, mul, scales, zeros);
}

void vecquant4matmul_cuda(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
); 

void vecquant4matmul(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
) {
  const at::cuda::OptionalCUDAGuard device_guard(device_of(vec));
  vecquant4matmul_cuda(vec, mat, mul, scales, zeros);
}

void vecquant8matmul_cuda(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
); 

void vecquant8matmul(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
) {
  const at::cuda::OptionalCUDAGuard device_guard(device_of(vec));
  vecquant8matmul_cuda(vec, mat, mul, scales, zeros);
}

void vecquant4transposematmul_cuda(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
); 

void vecquant4transposematmul(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
) {
  const at::cuda::OptionalCUDAGuard device_guard(device_of(vec));
  vecquant4transposematmul_cuda(vec, mat, mul, scales, zeros);
}

void vecquant4matmul_half_cuda(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
); 

void vecquant4matmul_half(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
) {
  const at::cuda::OptionalCUDAGuard device_guard(device_of(vec));
  vecquant4matmul_half_cuda(vec, mat, mul, scales, zeros);
}

void vecquant4transposematmul_half_cuda(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
); 

void vecquant4transposematmul_half(
  torch::Tensor vec, torch::Tensor mat, torch::Tensor mul,
  torch::Tensor scales, torch::Tensor zeros
) {
  const at::cuda::OptionalCUDAGuard device_guard(device_of(vec));
  vecquant4transposematmul_half_cuda(vec, mat, mul, scales, zeros);
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("vecquant2matmul", &vecquant2matmul, "Vector 2-bit Quantized Matrix Multiplication (CUDA)");
  m.def("vecquant3matmul", &vecquant3matmul, "Vector 3-bit Quantized Matrix Multiplication (CUDA)");
  m.def("vecquant4matmul", &vecquant4matmul, "Vector 4-bit Quantized Matrix Multiplication (CUDA)");
  m.def("vecquant8matmul", &vecquant8matmul, "Vector 8-bit Quantized Matrix Multiplication (CUDA)");
  m.def("vecquant4transposematmul", &vecquant4transposematmul, "Vector 4-bit Transpose Quantized Matrix Multiplication (CUDA)");
  m.def("vecquant4matmul_half", &vecquant4matmul_half, "Vector 4-bit Half Quantized Matrix Multiplication (CUDA)");
  m.def("vecquant4transposematmul_half", &vecquant4transposematmul_half, "Vector 4-bit Half Transpose Quantized Matrix Multiplication (CUDA)");
}
