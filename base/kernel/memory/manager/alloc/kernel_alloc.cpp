#include "kernel/kernel.hpp"

void* operator new(unsigned int size){
    return hunos::kernel::getKernel()->kernel_alloc_manager()->malloc(size);
}
 
void* operator new[](unsigned int size){
    return hunos::kernel::getKernel()->kernel_alloc_manager()->malloc(size);
}
 
void operator delete(void* p){
    return hunos::kernel::getKernel()->kernel_alloc_manager()->free(p);
}
 
void operator delete[](void* p){
    return hunos::kernel::getKernel()->kernel_alloc_manager()->free(p);
}
