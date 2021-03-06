#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_games;
    scanf("%d", &no_of_games);

    vector <int> won(no_of_games + 1);
    for(int i = 1; i <= no_of_games; i++)
        scanf("%d", &won[i]);

    vector <int> wins_from(no_of_games + 2, 0);
    for(int i = no_of_games; i >= 1; i--)
        wins_from[i] = wins_from[i + 1] + (won[i]);

    int final_no_of_games = 0;
    int losses_so_far = 0;
    for(int i = 1; i <= no_of_games; i++)
    {
        losses_so_far += (!won[i]);

        final_no_of_games = max(final_no_of_games, losses_so_far + wins_from[i]);
    }

    printf("%d\n", final_no_of_games);
    return 0;
}
