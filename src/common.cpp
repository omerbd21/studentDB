#include <string>
#include <vector>
using namespace std;
bool in_array(string value, string* array)
{
    int arrayLength = sizeof(array)/ sizeof(value);
    for (int i=0; i<arrayLength; i++)
    {
        if (array[i] ==value)
        {
          return true;
        }
    };
    return false;
}
