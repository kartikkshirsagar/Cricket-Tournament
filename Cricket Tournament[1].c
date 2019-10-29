/*Some crucial assumptions
There are always enough batsmen and bowlers present as per the requirements.
There are only two best batsmen or bowlers in a team(i.e no 3 best players).

*/




#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct player
{
    /* data */
    int player_id;
    int match_id;
    int previous_total_score;
    float previous_avg;
    int previous_total_wickets;
    float previous_wicket_avg;
    int total_runs_in_last_five_matches;
    int total_wickets_in_last_five_matches;
    int century;
    int present_match_score;
    int present_match_wicket;
    char player_role[10];
    enum playing{out,notout};

}p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15;




struct team
{
    /* data */
   struct player all_players[15];//array of structure

}t1,t2,t3,t4,t5,t6,t7,t8;




struct match_played
{
    /* data */
    int match_id;
    struct team teams_played[2];
    int highest_runs;
    struct player man_of_the_match;
    int wicket_taken_by_pacers;
    enum match_result{win,NR,tie};
    struct team winning_team;



};


void printPlayerStructure(struct team player)
{
    printf("");
}


void swapstructure(struct player* a, struct player* b) 
{ 
    struct player t = *a; 
    *a = *b; 
    *b = t; 
} 
  



int partitionBat (struct player arr[], int low, int high) 
{ 
    struct player pivot = arr[high];  
        int i = low;
        int j = high-1;

    while(high>low)
    {    
        while(arr[i].previous_avg>pivot.previous_avg)
        {
            i++;
        }
        while(arr[j].previous_avg<=pivot.previous_avg)
        {
            j--;
        }
        if(arr[i].previous_avg<=pivot.previous_avg && arr[j].previous_avg>pivot.previous_avg )
        {
            swapstructure(&arr[i],&arr[j]);
            i++;
            j--;

        }
        swapstructure(&arr[j], &arr[high]); 
         
    }
    return (j);
} 


int partitionBowl (struct player arr[], int low, int high) 
{ 
    struct player pivot = arr[high];  
        int i = low;
        int j = high-1;

    while(high>low)
    {    
        while(arr[i].previous_total_wickets>pivot.previous_total_wickets)
        {
            i++;
        }
        while(arr[j].previous_total_wickets<=pivot.previous_total_wickets)
        {
            j--;
        }
        if(arr[i].previous_total_wickets<=pivot.previous_total_wickets && arr[j].previous_total_wickets>pivot.previous_total_wickets)
        {
            swapstructure(&arr[i],&arr[j]);
            i++;
            j--;

        }
        swapstructure(&arr[j], &arr[high]); 
         
    }
    return (j);
} 
  



void quickSortStructureBat(struct player arr[], int low, int high) 
{ 
    if (low < high) 
    {    
        int pi = partitionBat(arr, low, high);   
        quickSortStructureBat(arr, low, pi - 1); 
        quickSortStructureBat(arr, pi + 1, high); 
    } 
} 



void quickSortStructureBowl(struct player arr[], int low, int high) 
{ 
    if (low < high) 
    {    
        int pi = partitionBowl(arr, low, high);   
        quickSortStructureBowl(arr, low, pi - 1); 
        quickSortStructureBowl(arr, pi + 1, high); 
    } 
} 



void playing_eleven(struct team x)
{   
    struct team sorted_team_batting=x;
    struct team sorted_team_bowling=x;
    int selected[10];
    //struct team final_eleven;
    int i=0,j=0;

    quickSortStructureBat(sorted_team_batting.all_players,0,15);
    quickSortStructureBowl(sorted_team_bowling.all_players,0,15);

    while(i<2)
    {
        printf("%d",sorted_team_batting.all_players[i].player_id);
        selected[j]=sorted_team_batting.all_players[i].player_id;
        j++;
        printf("%d",sorted_team_bowling.all_players[i].player_id);
        selected[j]=sorted_team_bowling.all_players[i].player_id;
        j++;
        i++;
    }

    for ( i = 0; i < 15; i++)
    {
        if(x.all_players[i].player_role[1]=='a')
        {
            
        }
    }
    






}


int main()
{
    
    return 0;
}

