#include "MathUtility.h"
float sum=0.0;
float calculate_average(vector<float> values)
{
  for_each(values.begin(),values.end(),[&sum](int &x){sum=sum+x;});
  return sum/(values.size());
}
