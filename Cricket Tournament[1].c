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

void deletePlayer(struct player* a,int sz,int i)
{
    while(i<sz)
    {
        a[i]=a[i+1];
        i++;
    }
}

void playing_eleven(struct team x)
{   
    struct team sorted_team_batting=x;
    struct team sorted_team_bowling=x;
    int selected[10];//This is array of those player ids who are the best (both batsmen ans bowlers)
    struct player batsmen[10];
    struct player bowlers[10];
    struct player allRounders[10];
    //struct team final_eleven;
    int i=0,j=0;

    quickSortStructureBat(sorted_team_batting.all_players,0,15);
    quickSortStructureBowl(sorted_team_bowling.all_players,0,15);

    while(i<2)
    {
        printf("%d\n",sorted_team_batting.all_players[i].player_id);
        selected[j]=sorted_team_batting.all_players[i].player_id;
        j++;
        printf("%d\n",sorted_team_bowling.all_players[i].player_id);
        selected[j]=sorted_team_bowling.all_players[i].player_id;
        j++;
        i++;
    }
    for ( i = 0; i < 15; i++)
    {
        if(x.all_players[i].player_id==selected[0]||x.all_players[i].player_id==selected[1]||x.all_players[i].player_id==selected[2]||x.all_players[i].player_id==selected[3])
        {
            j=i;
            while(j<15)
            {
                x.all_players[i]=x.all_players[i+1];
                j++;
            }
        }
    }
    
    j=0;int k=0,l=0;
    for ( i = 0; i < 11; i++)
    {
        if(x.all_players[i].player_role[1]=='a')
        {
            batsmen[j]=x.all_players[i];
            j++;
        }
        if(x.all_players[i].player_role[1]=='o')
        {
            bowlers[k]=x.all_players[i];
            k++;
        }
        else
        {
            allRounders[l]=x.all_players[i];
            l++;
        }
    }
    int batsmenSize=(sizeof(batsmen)/sizeof(batsmen[0]));
    struct player* temp;
    int batsmencombination[3][batsmenSize];
    
    l=0;
    printf("Combinations among Batsmen are:\n");
    for(i=0;i<batsmenSize-2;i++)        //i is less than n-r+1 = size-3+1=size-2
    {
        for(j= i+1;i < batsmenSize-1;j++)
        {
            for (k = j+1; i < batsmenSize; k++)
            {
               batsmencombination[0][l]=batsmen[i].player_id;
               batsmencombination[1][l]=batsmen[j].player_id;
               batsmencombination[2][l]=batsmen[k].player_id;
               l++;
            }
            
        }

    }

    int bowlersSize=(sizeof(bowlers)/sizeof(bowlers[0]));
    int bowlerscombination[2][bowlersSize];
    printf("Combinations among Bowlers are:\n");
    l=0;
    for ( i = 0; i < bowlersSize - 1; i++)
    {
        for ( j = i+1; i <bowlersSize ; j++)
        {
            bowlerscombination[0][l]=bowlers[i].player_id;
            bowlerscombination[1][l]=bowlers[j].player_id;
            l++;
        }
        
    }
    int batsmenandbowlerscombination[5][batsmenSize*bowlersSize];
    i=0;
    while(i<batsmenSize*bowlersSize)
    {
        batsmenandbowlerscombination[0][i]=batsmencombination[0][i];
        batsmenandbowlerscombination[1][i]=batsmencombination[1][i];
        batsmenandbowlerscombination[2][i]=batsmencombination[2][i];
        batsmenandbowlerscombination[3][i]=bowlerscombination[0][i];
        batsmenandbowlerscombination[4][i]=bowlerscombination[1][i];
        i++;
    }
    
    






}


int main()
{
    
    return 0;
}

