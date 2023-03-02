


## head overflow demo1
* code
```
int func1(void)
{
    char *p = (char*)malloc(sizeof(char) * 15);
    p[15] = 0x00; //申请15字节内存， 对齐后是16字节
    free(p);

    return 0;
}
```

```
==41813==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x60200000001f at pc 0x557da78ab21f bp 0x7fff6e805ed0 sp 0x7fff6e805ec0
WRITE of size 1 at 0x60200000001f thread T0
    #0 0x557da78ab21e in func1() /root/c20/sanitizer_test/src/sanitizer_heap_overflow.cpp:8
    #1 0x557da78ab24c in main /root/c20/sanitizer_test/src/sanitizer_heap_overflow.cpp:16
    #2 0x7f1e343ad50f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x7f1e343ad5c8 in __libc_start_main_impl ../csu/libc-start.c:381
    #4 0x557da78ab104 in _start (/c20/github.com/cpp20_study/sanitizer_test/build/sanitizer_heap_overflow+0x1104)

0x60200000001f is located 0 bytes to the right of 15-byte region [0x602000000010,0x60200000001f)
allocated by thread T0 here:
    #0 0x7f1e3498190f in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:69
    #1 0x557da78ab1de in func1() /root/c20/sanitizer_test/src/sanitizer_heap_overflow.cpp:7
    #2 0x557da78ab24c in main /root/c20/sanitizer_test/src/sanitizer_heap_overflow.cpp:16
    #3 0x7f1e343ad50f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: heap-buffer-overflow /root/c20/sanitizer_test/src/sanitizer_heap_overflow.cpp:8 in func1()
Shadow bytes around the buggy address:
  0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c047fff8000: fa fa 00[07]fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
```


