#include <iostream>
#include <cmath>
#include <algorithm>
#define HAND 5
#define print(...) std::cout << __VA_ARGS__ << "\n"

int CheckCards(int cards[HAND], int suits[HAND])
{
    bool straight = true;
    bool flush = true;
    for (int i = 0; i < HAND - 1; i++)
        if (cards[i + 1] != cards[i] + 1)
            straight = false;
    for (int i = 0; i < HAND; i++)
        if (suits[i] != suits[0])
            flush = false;
    
    int pair = 0;
    bool three_kind = false;
    bool four_kind = false;
    for (int i = 0; i < HAND; i++)
    {
        int match = 0;
        for (int j = 0; j < HAND; j++)
            if (cards[i] == cards[j])
                match++;
        match -= 1;                             //Card will always match itself                    
        if (!match)
            continue;
        else if (match == 1)
            pair++;
        else if (match == 2)
            three_kind = true;
        else if (match == 3)
            four_kind = true;
    }

    pair -= 2; //The matching cards will count each other
    if (straight && flush && cards[0] == 8) 
        return 1;                               //Royal Flush
    else if (straight && flush)                 
        return 2;                               //Straight Flush
    else if (straight)
        return 3;                               //Straight
    else if (flush)
        return 4;                               //Flush
    else if (four_kind)
        return 5;                               //Four of a kind
    else if (pair = 2 && three_kind)
        return 6;                               //Full House
    else if (three_kind)
        return 7;                               //Three of a kind
    else if (pair = 2)
        return 8;                               //Two Pair
    else if (pair = 1)
        return 9;                               //One Pair
    else
        return 10;                              //High Card
}

int main()
{
    print("Input 5 nums 0-51");
    int cards[5] = {0};
    int ranks[5] = {0};
    int suits[5] = {0};
    for (int i = 0; i < HAND; i++)
        scanf("%i",&cards[i]);

    for (int i = 0; i < HAND; i++)
    {
        ranks[i] = cards[i] % 13;
        suits[i] = cards[i] / 13;
    }
    std::sort(ranks, ranks + (sizeof(ranks) / sizeof(int)));
    
    switch (CheckCards(ranks, suits))
    {
        case 1:
        print("Royal Flush");
        break;
        case 2:
        print("Straight Flush");
        break;
        case 3:
        print("Straight");
        break;
        case 4:
        print("Flush");
        break;
        case 5:
        print("Four of a Kind");
        break;
        case 6:
        print("Full House");
        break;
        case 7:
        print("Three of a Kind");
        break;
        case 8:
        print("Two Pair");
        break;
        case 9:
        print("One Pair");
        break;
        case 10:
        print("High Card");
        break;
        default:
        print("Error in Check Function");
        break;
    }
    return 0;
}