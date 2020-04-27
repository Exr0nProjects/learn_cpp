// treap array rewrite, hopefully clean (27 Apr 2020)

#include <iostream>	// io
#include <cassert> 	// assert

const int MX = 100111;

int value[MX], weight[MX], left[MX], right[MX], root=0, alloc=1;

//        R	         R	
//        |	         |	
//       cur	        thn	
//      /   \   --->   /   \
//    thn    C	      A	   cur	
//   /   \	          /   \
//  A     B	   	 B     C

int rotR(int &cur)
{
    assert(left[cur]);
    // TODO: how to update pointer from parent?   
}

