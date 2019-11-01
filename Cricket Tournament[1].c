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
    char player_name[40];
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
    enum {out,notout} playing;

};




struct team
{
   struct player all_players[15];//array of structure
   int team_id;

}t1,t2,t3,t4,t5,t6,t7,t8;





struct match_played
{
    /* data */
    int match_id;
    struct team teams_played[2];
    int highest_runs;
    struct player man_of_the_match;
    int wicket_taken_by_pacers;
    enum {win,NR,tie} match_result;
    struct team winning_team;



};

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
        //printf("%d\n",sorted_team_batting.all_players[i].player_id);
        selected[j]=sorted_team_batting.all_players[i].player_id;
        j++;
        //printf("%d\n",sorted_team_bowling.all_players[i].player_id);
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
    struct team temp;
    int batsmencombination[3][batsmenSize];
    
    l=0;
    printf("Combinations among Batsmen are:\n");
    for(i=0;i<batsmenSize-2;i++)        //i is less than n-r+1 = size-3+1=size-2
    {
        for(j= i+1;j < batsmenSize-1;j++)
        {
            for (k = j+1; k < batsmenSize; k++)
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
        for ( j = i+1; j <bowlersSize ; j++)
        {
            bowlerscombination[0][l]=bowlers[i].player_id;
            bowlerscombination[1][l]=bowlers[j].player_id;
            l++;
        }
        
    }
    int size1=batsmenSize*bowlersSize;
    int batsmenandbowlerscombination[5][size1];
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



  int final_eleven[7][size1*15];  // 6C2 would be 15, so we know the size
  
  
 int z;
 for  (z = 0; i < size1*15; z++) 
   {
        temp=x;
        i=0;j=0;
        while(i<5)
        {
            while(j<15)
            if(temp.all_players[j].player_id==batsmenandbowlerscombination[i][z])
            {
                deletePlayer(temp.all_players,11,j);
                j++;
            }
            i++;

        }
        int last_size=(sizeof(temp.all_players)/sizeof(temp.all_players[0]));
        int final_combination[2][last_size];
        l=0;
        for ( i = 0; i < 5; i++)
        {
            for (j = i+1; j < 6 ; j++)
            {
            final_combination[0][l] =temp.all_players[i].player_id;
            final_combination[1][l]=temp.all_players[j].player_id;
            l++;

            }
            
        }
        j=15*z;
        while(j<j+15)
        {
            int y=0;
            while(y<5)
            {
                final_eleven[y][j]=batsmenandbowlerscombination[y][z];
                y++;
            }
            final_eleven[y+1][0]=final_combination[0][j-15*z];
            final_eleven[y+2][0]=final_combination[1][j-15*z];
            j++;
        }
        
    }
}

//Highest individual run 
void mergeself(struct player A[],int l,int m,int n,struct player C[])
{
	int i=l,j=m+1,k=l;
	while(i<=m && j<=n)
	{
		if(A[i].player_name<A[j].player_name)
			C[k++]=A[i++];
		else
			C[k++]=A[j++];
	}
	
	if(i<=m)
		while(i<=m)C[k++]=A[i++];
	else
		while(j<=n)C[k++]=A[j++];
	
	for(i=l;i<=n;++i)
		A[i]=C[i];
	
	
}

void Mergesort(struct player A[],int low,int high,struct player C[])
{
	
	int i;
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		Mergesort(A,low,mid,C);
		Mergesort(A,mid+1,high,C);
		mergeself(A,low,mid,high,C);
	}
}


void highest_run(struct team t[])
{

	
	int i,j,k=0;struct player a[120],c[120];				//a[] to store required players
	int max=t[0].all_players[0].previous_total_score+t[0].all_players[0].present_match_score;
	
	
	for(i=0;i<8;++i)
	{
		int runs=t[i].all_players[i].previous_total_score+t[i].all_players[i].present_match_score;
		for(j=0;j<15;++j)
		{
			if(runs>=max)
			{
				if(runs==max)
				{
					a[k]=t[i].all_players[j];
					k++;
				}
				else {
					k=0;
					max=runs;
					a[k]=t[i].all_players[j];
					k++;
				}
			}
		}
	}
	
	Mergesort(a,0,k,c);
	for(i=0;i<k;++i)
	{
		printf("Name= %s  Runs= %d\n",a[i].player_name,a[i].previous_total_score+a[i].present_match_score);
	}	
	
}


float calculate_average(struct team a,int i){
    float avg;
    int number_of_outs = a.all_players[i].previous_total_score/a.all_players[i].previous_avg;
    a.all_players[i].previous_total_score += a.all_players[i].present_match_score;
    
    if(a.all_players[i].playing==notout)
    {
        a.all_players[i].previous_avg=a.all_players[i].previous_total_score/number_of_outs;
    }
    else
    {
        a.all_players[i].previous_avg=a.all_players[i].previous_total_score/(number_of_outs +1);
    }
    return a.all_players[i].previous_avg;
}


struct player highest_average(int n)
{  

    struct team all_teams[8]={t1,t2,t3,t4,t5,t6,t7,t8};
    struct player player_highest_avg;
    int i,j,maxavg,pos;
    int k =0;
    float avg[120];
    for (i = 0; i < 8 ; i++)
    {
        for (j = 0; j < 15 ; j++)
        {
            avg[k] = calculate_average(all_teams[i],j);
            k++;
        }
        
    }

    maxavg=avg[0];
    //INSERT MAX ELEMENT IN ARRAY ALGO HERE
    for(i=0;i<120;++i)
    {
        if(avg[i]>maxavg)
        {
            maxavg=avg[i];
 
        }
    }
    k=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<15;++j)
        {
            if(avg[k]==maxavg)
            {
                player_highest_avg=all_teams[i].all_players[j];
            }
            k++;
        }
    }
    
    //RETURN THE PLAYER WHICH HAS MAX AVERAGE
    return player_highest_avg;

}

void Init (struct team* a,int pointsTable[][2],int sz1)
{
    for(int i=0;i<sz1;i++)
    {
        pointsTable[i][1]=0;
        pointsTable[i][0]=a[i].team_id;
    }
}


void beginTournament(struct team* teams_playing,int pointsTable[][2],int sz,int groupsize)
{   
    void print4largest(int pointsTable[][2],int hi, int lo);
    int i=0,j=0;int k;
    int ans;
    printf("Matches will be played now in Group 1\n");
    for(i=0;i<groupsize-1;i++)
    {
        for (j = i+1; j < groupsize; j++)
        {
            printf("Match is being played between %d and %d\n",teams_playing[i].team_id,teams_playing[j].team_id);
            printf("Who will win? Enter the id and type -1 for tie\n");
            scanf("%d",&ans);
            if(ans==-1)
            {
                for(k=0;k<2*groupsize;k++)
                {   
                    if(pointsTable[k][0]==teams_playing[i].team_id||pointsTable[k][0]==teams_playing[j].team_id)
                    {
                        pointsTable[k][1]++;
                    }
                }
            }
            else{
                for(k=0;k<2*groupsize;k++)
                {   
                    if(pointsTable[k][0]==ans)
                    {
                        pointsTable[k][1]+=2;
                    }
                }
            }
        }
        
    }





    printf("Matches will be played now in Group 2\n");
    for(i=groupsize;i<2*groupsize-1;i++)
    {
        for (j = i+1; j < 2*groupsize; j++)
        {
            printf("Match is being played between %d and %d\n",teams_playing[i].team_id,teams_playing[j].team_id);
            printf("Who will win? Enter the id and type -1 for tie\n");
            scanf("%d",&ans);
            if(ans==-1)
            {
                for(k=0;k<2*groupsize;k++)
                {   
                    if(pointsTable[k][0]==teams_playing[i].team_id||pointsTable[k][0]==teams_playing[j].team_id)
                    {
                        pointsTable[k][1]++;
                    }
                }
            }
            else{
                for(k=0;k<2*groupsize;k++)
                {   
                    if(pointsTable[k][0]=ans)
                    {
                        pointsTable[k][1]+=2;
                    }
                }
            }
        }
        
    }
    print4largest(pointsTable,0,groupsize);
    print4largest(pointsTable,groupsize,2*groupsize);

 //SOrt teams playing array from 0 to groupsize-1 and groupsize to n-1
 //then top 2 teams from each group would advance to the knock outs.  
 /* Function to print the second largest element */



}

void print4largest(int pointsTable[][2], int lo,int hi) 
{ 
	int i, first, second; 
	first = second=pointsTable[lo][1]; 
	for (i = lo; i < hi ; i ++) 
	{ 
		if (pointsTable[i][1] > first) 
		{ 
			second = first; 
			first = pointsTable[i][1]; 
		} 

		else if (pointsTable[i][1] > second && pointsTable[i][1] != first) 
			second = pointsTable[i][1]; 
	}  	
    
    for(i=lo;i<hi;i++)
    {
        if(pointsTable[i][1]==first || pointsTable[i][1]==second)
        {
            printf("These teams will proceed to knock outs\n");

            printf("%d\n",pointsTable[i][0]);
        }
    }
} 



    








int main()
{
    int n,i;
    int pointsTable[8][2];    
    printf("Enter the number of teams:\n");
    scanf("%d",&n);
    struct team teams_playing[n];
    int groupsize=n/2;
    printf("Please Enter team ID's\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&teams_playing[i].team_id);
    }
    Init(teams_playing,pointsTable,n);
    beginTournament(teams_playing,pointsTable,n,groupsize);

    
    return 0;
}

