#ifndef _KERNEL_HPP
#define _KERNEL_HPP

#include "kernel_abstract.hpp"

namespace hunos {
namespace kernel {

KernelAbstract* initKernel();
KernelAbstract* getKernel();

}  // namespace kernel
}  // namespace hunos

#endif
