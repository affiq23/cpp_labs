//
//  main.cpp
//  reverse2DArray
//
//  Created by Affiq Mohammed on 11/3/22.
//

#include <iostream>
using namespace std;

int main()
{
   int arr[4][3];
   
   for (int i = 0; i < 4; ++i)
   {
      for (int j = 0; j < 3; ++j)
      {
         cin >> arr[i][j];
      }
   }
   
   for (int i = 0; i < 4; ++i)
   {
      for (int j = 0; j < 3; ++j)
      {
         cout << arr[3-i][2-j] << " ";
      }         cout << endl;
   }
   return 0;

}

