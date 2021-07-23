# PTA1016
+ 字母表排序

## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210715095829.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210715095829.png';" /></details>

## 思路
怎么paired的也没说，只能猜，一个个查询，直到找到能paired的

## python
已经预料到会超时了。。
### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210717215021.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210717215021.png';" /></details>


## c++
纠结cin了好久，看到网上cin也是写的很难看，感觉确实不能一股脑cin就完事了？

[参考文献](https://blog.csdn.net/weixin_41513917/article/details/100128584)

### sscanf的bug

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210722215610.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210722215610.png';" /></details>

### sort buggy

<details>
    <summary>Details</summary>

====================[ Build | algorithms | Debug ]==============================
"C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" --build D:\Users\LND\Desktop\ereaseo\algorithms\cmake-build-debug --target algorithms -- -j 9
[  9%] Built target gtest
Scanning dependencies of target algorithms
[ 14%] Building CXX object CMakeFiles/algorithms.dir/PTA/PTA1016/PhoneBills.cpp.obj
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h: In instantiation of 'void std::__sort(_RandomAccessIterator, _RandomAccessIterator, _Compare) [with _RandomAccessIterator = std::_List_const_iterator<record_>; _Compare = __gnu_cxx::__ops::_Iter_comp_iter<PhoneBills()::<lambda(auto:1, auto:2)> >]':
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:4866:18:   required from 'void std::sort(_RAIter, _RAIter, _Compare) [with _RAIter = std::_List_const_iterator<record_>; _Compare = PhoneBills()::<lambda(auto:1, auto:2)>]'
D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:70:10:   required from here
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: error: no match for 'operator-' (operand types are 'std::_List_const_iterator<record_>' and 'std::_List_const_iterator<record_>')
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algobase.h:67,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/char_traits.h:39,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/ios:40,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/istream:38,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/fstream:38,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:5:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_iterator.h:389:5: note: candidate: 'template<class _IteratorL, class _IteratorR> decltype ((__y.base() - __x.base())) std::operator-(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_IteratorR>&)'
     operator-(const reverse_iterator<_IteratorL>& __x,
     ^~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_iterator.h:389:5: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::reverse_iterator<_Iterator>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algobase.h:67,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/char_traits.h:39,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/ios:40,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/istream:38,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/fstream:38,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:5:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_iterator.h:1185:5: note: candidate: 'template<class _IteratorL, class _IteratorR> decltype ((__x.base() - __y.base())) std::operator-(const std::move_iterator<_IteratorL>&, const std::move_iterator<_IteratorR>&)'
     operator-(const move_iterator<_IteratorL>& __x,
     ^~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_iterator.h:1185:5: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::move_iterator<_IteratorL>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/vector:65,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/googletest/googletest/include/gtest/gtest.h:60,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:6:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_bvector.h:210:3: note: candidate: 'std::ptrdiff_t std::operator-(const std::_Bit_iterator_base&, const std::_Bit_iterator_base&)'
   operator-(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y)
   ^~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_bvector.h:210:3: note:   no known conversion for argument 1 from 'std::_List_const_iterator<record_>' to 'const std::_Bit_iterator_base&'
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:592,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/detail/conversions/from_json.hpp:13,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/adl_serializer.hpp:6,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:49,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note: candidate: 'template<class _Dom1, class _Dom2> std::_Expr<std::_BinClos<std::__minus, std::_Expr, std::_Expr, _Dom1, _Dom2>, typename std::__fun<std::__minus, typename _Dom1::value_type>::result_type> std::operator-(const std::_Expr<_Dom1, typename _Dom1::value_type>&, const std::_Expr<_Dom2, typename _Dom2::value_type>&)'
     _DEFINE_EXPR_BINARY_OPERATOR(-, __minus)
     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::_Expr<_Dom1, typename _Dom1::value_type>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:592,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/detail/conversions/from_json.hpp:13,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/adl_serializer.hpp:6,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:49,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note: candidate: 'template<class _Dom> std::_Expr<std::_BinClos<std::__minus, std::_Expr, std::_Constant, _Dom, typename _Dom::value_type>, typename std::__fun<std::__minus, typename _Dom1::value_type>::result_type> std::operator-(const std::_Expr<_Dom1, typename _Dom1::value_type>&, const typename _Dom::value_type&)'
     _DEFINE_EXPR_BINARY_OPERATOR(-, __minus)
     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::_Expr<_Dom1, typename _Dom1::value_type>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:592,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/detail/conversions/from_json.hpp:13,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/adl_serializer.hpp:6,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:49,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note: candidate: 'template<class _Dom> std::_Expr<std::_BinClos<std::__minus, std::_Constant, std::_Expr, typename _Dom::value_type, _Dom>, typename std::__fun<std::__minus, typename _Dom1::value_type>::result_type> std::operator-(const typename _Dom::value_type&, const std::_Expr<_Dom1, typename _Dom1::value_type>&)'
     _DEFINE_EXPR_BINARY_OPERATOR(-, __minus)
     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::_Expr<_Dom1, typename _Dom1::value_type>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:592,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/detail/conversions/from_json.hpp:13,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/adl_serializer.hpp:6,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:49,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note: candidate: 'template<class _Dom> std::_Expr<std::_BinClos<std::__minus, std::_Expr, std::_ValArray, _Dom, typename _Dom::value_type>, typename std::__fun<std::__minus, typename _Dom1::value_type>::result_type> std::operator-(const std::_Expr<_Dom1, typename _Dom1::value_type>&, const std::valarray<typename _Dom::value_type>&)'
     _DEFINE_EXPR_BINARY_OPERATOR(-, __minus)
     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::_Expr<_Dom1, typename _Dom1::value_type>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:592,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/detail/conversions/from_json.hpp:13,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/adl_serializer.hpp:6,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:49,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note: candidate: 'template<class _Dom> std::_Expr<std::_BinClos<std::__minus, std::_ValArray, std::_Expr, typename _Dom::value_type, _Dom>, typename std::__fun<std::__minus, typename _Dom1::value_type>::result_type> std::operator-(const std::valarray<typename _Dom::value_type>&, const std::_Expr<_Dom1, typename _Dom1::value_type>&)'
     _DEFINE_EXPR_BINARY_OPERATOR(-, __minus)
     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/valarray_after.h:403:5: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::_Expr<_Dom1, typename _Dom1::value_type>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/detail/conversions/from_json.hpp:13,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/adl_serializer.hpp:6,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:49,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:1173:1: note: candidate: 'template<class _Tp> std::_Expr<std::_BinClos<std::__minus, std::_ValArray, std::_ValArray, _Tp, _Tp>, typename std::__fun<std::__minus, _Tp>::result_type> std::operator-(const std::valarray<_Tp>&, const std::valarray<_Tp>&)'
 _DEFINE_BINARY_OPERATOR(-, __minus)
 ^~~~~~~~~~~~~~~~~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:1173:1: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::valarray<_Tp>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/detail/conversions/from_json.hpp:13,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/adl_serializer.hpp:6,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:49,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:1173:1: note: candidate: 'template<class _Tp> std::_Expr<std::_BinClos<std::__minus, std::_ValArray, std::_Constant, _Tp, _Tp>, typename std::__fun<std::__minus, _Tp>::result_type> std::operator-(const std::valarray<_Tp>&, const _Tp&)'
 _DEFINE_BINARY_OPERATOR(-, __minus)
 ^~~~~~~~~~~~~~~~~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:1173:1: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::valarray<_Tp>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/detail/conversions/from_json.hpp:13,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/adl_serializer.hpp:6,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:49,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:1173:1: note: candidate: 'template<class _Tp> std::_Expr<std::_BinClos<std::__minus, std::_Constant, std::_ValArray, _Tp, _Tp>, typename std::__fun<std::__minus, _Tp>::result_type> std::operator-(const _Tp&, const std::valarray<_Tp>&)'
 _DEFINE_BINARY_OPERATOR(-, __minus)
 ^~~~~~~~~~~~~~~~~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/valarray:1173:1: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::valarray<_Tp>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/deque:64,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/stack:60,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/regex:47,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:24:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_deque.h:352:5: note: candidate: 'template<class _Tp, class _Ref, class _Ptr> typename std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type std::operator-(const std::_Deque_iterator<_Tp, _Ref, _Ptr>&, const std::_Deque_iterator<_Tp, _Ref, _Ptr>&)'
     operator-(const _Deque_iterator<_Tp, _Ref, _Ptr>& __x,
     ^~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_deque.h:352:5: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::_Deque_iterator<_Tp, _Ref, _Ptr>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/deque:64,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/stack:60,
                 from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/regex:47,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:24:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_deque.h:364:5: note: candidate: 'template<class _Tp, class _RefL, class _PtrL, class _RefR, class _PtrR> typename std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type std::operator-(const std::_Deque_iterator<_Tp, _Ref, _Ptr>&, const std::_Deque_iterator<_Tp, _RefR, _PtrR>&)'
     operator-(const _Deque_iterator<_Tp, _RefL, _PtrL>& __x,
     ^~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_deque.h:364:5: note:   template argument deduction/substitution failed:
In file included from C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/algorithm:62,
                 from D:/Users/LND/Desktop/ereaseo/algorithms/json/include/nlohmann/json.hpp:37,
                 from D:\Users\LND\Desktop\ereaseo\algorithms\PTA\PTA1016\PhoneBills.cpp:7:
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1969:22: note:   'std::_List_const_iterator<record_>' is not derived from 'const std::_Deque_iterator<_Tp, _Ref, _Ptr>'
     std::__lg(__last - __first) * 2,
               ~~~~~~~^~~~~~~~~
C:/PROGRA~1/MINGW-~1/X86_64~1.0-W/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1880:5: warning: 'void std::__final_insertion_sort(_RandomAccessIterator, _RandomAccessIterator, _Compare) [with _RandomAccessIterator = std::_List_const_iterator<record_>; _Compare = __gnu_cxx::__ops::_Iter_comp_iter<PhoneBills()::<lambda(auto:1, auto:2)> >]' used but never defined
     __final_insertion_sort(_RandomAccessIterator __first,
     ^~~~~~~~~~~~~~~~~~~~~~
mingw32-make.exe[3]: *** [CMakeFiles\algorithms.dir\build.make:320: CMakeFiles/algorithms.dir/PTA/PTA1016/PhoneBills.cpp.obj] Error 1
mingw32-make.exe[2]: *** [CMakeFiles\Makefile2:177: CMakeFiles/algorithms.dir/all] Error 2
mingw32-make.exe[1]: *** [CMakeFiles\Makefile2:184: CMakeFiles/algorithms.dir/rule] Error 2
mingw32-make.exe: *** [Makefile:182: algorithms] Error 2

</details>

原因sort不能用于list，但是可以用于vector,并且line65对one的排序不影响record

[参考文献](http://c.biancheng.net/view/445.html)


### clear并不能清空缓存

如果需要清空缓存要使用,[参考文献](https://blog.csdn.net/zzw_17805056819/article/details/99574971)

[ostringstream是重量级对象](https://blog.csdn.net/billdavid/article/details/3899312?utm_source=blogxgwz2)

stringstream.str(""); 

### 第一次提交：后两个还是超时了
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210723235526.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210723235526.png';" /></details>


