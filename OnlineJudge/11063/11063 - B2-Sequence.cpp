#include <iostream>
using namespace std;

int main()
{
   int caseNum = 0;
   int n;
   while( cin >> n )
   {
      caseNum++;
      bool isB2Sequence = true; // isB2Sequence is true iff this sequence is a B2-sequenc

      int sequence[ 1001 ];
      for( int i = 0; i < n; i++ )
         cin >> sequence[ i ];

      for( int i = 0; i < n; i++ )
         if( sequence[ i ] < 1 )
         {
            isB2Sequence = false;
            break;
         }

      if( isB2Sequence )
      {
         for( int i = 1; i < n; i++ )
            if( sequence[ i - 1 ] >= sequence[ i ] )
            {
               isB2Sequence = false;
               break;
            }

         bool exist[ 20001 ] = {}; // exist[ k ] is true iff there is a pair whose sum is k
         if( isB2Sequence )
            for( int i = 0; i < n; i++ )
            {
               for( int j = i; j < n; j++ )
               {
                  int index = sequence[ i ] + sequence[ j ];
                  if( exist[ index ] )
                  {
                     isB2Sequence = false;
                     break;
                  }
                  else
                     exist[ index ] = true;
               }

               if( !isB2Sequence )
                  break;
            }
      }

      if( isB2Sequence )
         cout << "Case #" << caseNum << ": It is a B2-Sequence.\n\n";
      else
         cout << "Case #" << caseNum << ": It is not a B2-Sequence.\n\n";
   }
   return 0;
}