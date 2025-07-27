	.file	"9.cpp"
 # GNU C++17 (x86_64-posix-seh, Built by MinGW-Builds project) version 11.4.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.25-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=core2 -march=nocona -Ofast -fno-asynchronous-unwind-tables
	.text
	.p2align 4
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
__tcf_0:
 # C:/Program Files/RedPanda-Cpp/mingw64/lib/gcc/x86_64-w64-mingw32/11.4.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rcx	 #, tmp82
	jmp	_ZNSt8ios_base4InitD1Ev	 #
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
main:
	subq	$40, %rsp	 #,
 # C:/Users/wanglight/Documents/9.cpp:3: int main(){
	call	__main	 #
 # C:/Users/wanglight/Documents/9.cpp:11: }
	xorl	%eax, %eax	 #
	addq	$40, %rsp	 #,
	ret	
	.p2align 4
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
_GLOBAL__sub_I_main:
 # C:/Program Files/RedPanda-Cpp/mingw64/lib/gcc/x86_64-w64-mingw32/11.4.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rcx	 #, tmp82
 # C:/Users/wanglight/Documents/9.cpp:11: }
	subq	$40, %rsp	 #,
 # C:/Program Files/RedPanda-Cpp/mingw64/lib/gcc/x86_64-w64-mingw32/11.4.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	call	_ZNSt8ios_base4InitC1Ev	 #
	leaq	__tcf_0(%rip), %rcx	 #, tmp83
 # C:/Users/wanglight/Documents/9.cpp:11: }
	addq	$40, %rsp	 #,
 # C:/Program Files/RedPanda-Cpp/mingw64/lib/gcc/x86_64-w64-mingw32/11.4.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	jmp	atexit	 #
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_main
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (x86_64-posix-seh, Built by MinGW-Builds project) 11.4.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
