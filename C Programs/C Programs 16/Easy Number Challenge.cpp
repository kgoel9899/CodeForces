#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &number_of_divisors, int LIMIT)
{
    number_of_divisors[1] = 1;

    vector <int> largest_prime_factor(LIMIT + 1, 0);
    for(int i = 2; i <= LIMIT; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(int multiple = i; multiple <= LIMIT; multiple += i)
                largest_prime_factor[multiple] = i;
        }

        int exponent = 0;

        int reduced_i = i;
        while(reduced_i%largest_prime_factor[i] == 0)
        {
            reduced_i /= largest_prime_factor[i];
            exponent++;
        }

        number_of_divisors[i] = (exponent + 1)*number_of_divisors[reduced_i];
    }
}

int main()
{
    const int LIMIT = 1e6;
    vector <int> number_of_divisors(LIMIT + 1, 0);
    precompute(number_of_divisors, LIMIT);

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int sum = 0;
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            for(int k = 1; k <= c; k++)
            {
                sum += number_of_divisors[i*j*k];
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}
