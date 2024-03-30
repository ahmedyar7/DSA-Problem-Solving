class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {

        //  int count=0;
        float f = (float)(n);
        while (f > 1)
        {
            f = f / 2;
        }
        if (f == 1)
        {
            return true;
        }
        return false;
    }
}