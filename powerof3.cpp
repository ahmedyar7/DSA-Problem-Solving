class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // Step 1: Check if n is positive
        if (n <= 0)
        {
            return false;
        }

        // Step 2: Iteratively divide by 3
        while (n % 3 == 0)
        {
            n /= 3;
        }

        // Step 3: Check if we have reduced n to 1
        return n == 1;
    }
};
