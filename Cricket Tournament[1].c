/*Some crucial assumptions
There are always enough batsmen and bowlers present as per the requirements.
There are only two best batsmen or bowlers in a team(i.e no 3 best players).

*/




#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct player
{
    /* data */
    int player_id;
    char player_name[40];
    int match_id;
    long previous_total_score;
    float previous_avg;
    int previous_total_wickets;
    float previous_wicket_avg;
    int total_runs_in_last_five_matches;
    int total_wickets_in_last_five_matches;
    int century;
    int present_match_score;
    int present_match_wicket;
    char player_role[10];
    int playing;

};




struct team
{
   struct player all_players[15];//array of structure
   int team_id;

};





struct match_played
{
    /* data */
    int match_id;
    struct team teams_played[2];
    int highest_runs;
    int man_of_the_match;
    int wicket_taken_by_pacers;
    enum {win,NR,tie} match_result;
    int winning_team;



};


void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

long int fact(int n)
{
    int i;
    long int f=1;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void swapstructure(struct player* a, struct player* b) 
{ 
    struct player t = *a; 
    *a = *b; 
    *b = t; 
}

void bubbleSortbat(struct player* arr, int n) 
{ 
   int i, j,sorted=0; 
   for (i = 0; i < n-1 && sorted==0; i++) 
   {  
       sorted=1;
     for (j = 0; j < n-i-1; j++) 
     { 
            if (arr[j].previous_total_score < arr[j+1].previous_total_score) 
            { 
            swapstructure(&arr[j], &arr[j+1]);
            sorted=0; 
            } 
     } 
   }

   for(i=0;i<n-1;i++)
   {
       if(arr[i].previous_total_score==arr[i+1].previous_total_score)
       {
           if(arr[i+1].previous_avg > arr[i].previous_avg)
           {
               swapstructure(&arr[i+1],&arr[i]);
           }
       }
   } 
} 
void bubbleSortbowl(struct player* arr, int n) 
{ 
   int i, j,sorted=0; 
   for (i = 0; i < n-1 && sorted==0; i++) 
   {  
       sorted=1;
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j].previous_total_wickets < arr[j+1].previous_total_wickets) 
        { 
           swapstructure(&arr[j], &arr[j+1]);
           sorted=0; 
        } 
     } 
   }
   for(i=0;i<n-1;i++)
   {
       if(arr[i].previous_total_wickets==arr[i+1].previous_total_wickets)
       {
           if(arr[i+1].previous_wicket_avg > arr[i].previous_wicket_avg)
           {
               swapstructure(&arr[i+1],&arr[i]);
           }
       }
   } 
} 

void bubbleSortavg(struct player* arr,int n)
{

}
void deletePlayer(struct player* a,int sz,int i)
{
    while(i<sz-1)
    {
        a[i]=a[i+1];
        i++;
    }
}


void playing_eleven(struct team x)
{   
    struct team sorted_team_batting=x;
    struct team sorted_team_bowling=x;
    int selected[4];//This is array of those player ids who are the best (both batsmen ans bowlers)
    struct player batsmen[10];
    struct player bowlers[10];
    struct player allRounders[10];
    //struct team final_eleven;
    int i=0,j=0;
    /*int **final_eleven = (int **)malloc(7 * sizeof(int *)); 
    for (i=0; i<7; i++) 
         {
             final_eleven[i] = (int *)malloc(900 * sizeof(int));
         }*/

    bubbleSortbat(sorted_team_batting.all_players,15);
    bubbleSortbowl(sorted_team_bowling.all_players,15);

    selected[0]=sorted_team_batting.all_players[0].player_id;
    selected[1]=sorted_team_batting.all_players[1].player_id;
    selected[2]=sorted_team_bowling.all_players[0].player_id;
    selected[3]=sorted_team_bowling.all_players[1].player_id;
   /* while(i<2)
    {
        //printf("%d\n",sorted_team_batting.all_players[i].player_id);
        selected[j]=sorted_team_batting.all_players[i].player_id;
        j++;
        //printf("%d\n",sorted_team_bowling.all_players[i].player_id);
        selected[j]=sorted_team_bowling.all_players[i].player_id;
        j++;
        i++;
    }*/
    for ( i = 0; i < 15; i++)
    {
        if(x.all_players[i].player_id==selected[0])
        {
            j=i;
            deletePlayer(x.all_players,15,j);
        }
    }
    for ( i = 0; i < 15; i++)
    {
        if(x.all_players[i].player_id==selected[1])
        {
            j=i;
            deletePlayer(x.all_players,15,j);
        }
    }
    for ( i = 0; i < 15; i++)
    {
        if(x.all_players[i].player_id==selected[2])
        {
            j=i;
            deletePlayer(x.all_players,15,j);
        }
    }
    for ( i = 0; i < 15; i++)
    {
        if(x.all_players[i].player_id==selected[3])
        {
            j=i;
            deletePlayer(x.all_players,15,j);
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
        else if(x.all_players[i].player_role[1]=='o')
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
    i=0;
    while(batsmen[i].player_id!=0)
    {
        i++;
    }
    int batsmenSize=i;
    struct team temp;
    long int no_of_batsmencombi=fact(batsmenSize)/(fact(3)*fact(batsmenSize-3));
    int batsmencombination[3][no_of_batsmencombi];
    
    l=0;
    //printf("Combinations among Batsmen are:\n");
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
    i=0;
    while(bowlers[i].player_id!=0)
    {
        i++;
    }

    int bowlersSize=i;
    int no_of_bowlerscombi=fact(bowlersSize)/(fact(2)*fact(bowlersSize-2));
    int bowlerscombination[2][no_of_bowlerscombi];
    //printf("Combinations among Bowlers are:\n");
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
    int size1=no_of_batsmencombi*no_of_bowlerscombi;
    int batsmenandbowlerscombination[5][size1];

    /*int **batsmenandbowlerscombination = (int **)malloc(5 * sizeof(int *)); 
    for (i=0; i<5; i++) 
         {
             batsmenandbowlerscombination[i] = (int *)malloc(size1 * sizeof(int));
         }*/

    for(i=0;i<5;i++)
    {
        for ( j = 0; j < size1; j++)
        {
            batsmenandbowlerscombination[i][j]=0;
        }
        
    }
    i=0;j=0;k=0;
    while(i<no_of_batsmencombi)
    {
        j=0;
        while (j<no_of_bowlerscombi)
        {
            batsmenandbowlerscombination[0][k]=batsmencombination[0][i];
            batsmenandbowlerscombination[1][k]=batsmencombination[1][i];
            batsmenandbowlerscombination[2][k]=batsmencombination[2][i];
            batsmenandbowlerscombination[3][k]=bowlerscombination[0][j];
            batsmenandbowlerscombination[4][k]=bowlerscombination[1][j];
            j++;
            k++;
        }
        
        
        i++;
    }


           // 6C2 would be 15, so we know the size
 int final_eleven[7][900];
  
 int z;
 for  (z = 0; z < 60; z++) 
   {
        temp=x;
        i=0;j=0;
        while(i<5)
        {
            j=0;
            while(j<11)
	        {
	            if(temp.all_players[j].player_id==batsmenandbowlerscombination[i][z])
                    {
                        deletePlayer(temp.all_players,11,j);
                    }
	            j++;
	        }
            i++;
        }
        int last_size=(sizeof(temp.all_players)/sizeof(temp.all_players[0]));
	    long int no_of_lastcombi=fact(last_size)/(fact(2)*fact(last_size-2));
        int final_combination[2][15];
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
        i=0;j=0;
        while(i<15)
        {
            j=0;
            while(j<5)
            {
                final_eleven[j][i + z*15]=batsmenandbowlerscombination[j][z];
                //fprintf("abc.txt","%d\n",batsmenandbowlerscombination[j][z]);
                j++;
            }
            final_eleven[j][i + z*15]=final_combination[0][i];
            final_eleven[j+1][i + z*15]=final_combination[1][i];
            //fprintf("abc.txt","%d\n",final_combination[0][i]);
            //fprintf("abc.txt","%d\n\n\n",final_combination[1][i]);
            i++;
        }
        
    }

   /* for (i=0; i<5; i++) 
         {
            free(batsmenandbowlerscombination);
         } 
free(*batsmenandbowlerscombination);*/
	FILE* result;
    result=fopen("result.txt","w");

    printf("These players are the top two batsmen and bowlers so they will be always there in the playing eleven,their player IDs are:\n");
    printf(" %d\n",selected[0]);
    printf(" %d\n",selected[1]);
    printf(" %d\n",selected[2]);
    printf(" %d\n",selected[3]);
	
    for ( j = 0; j < 7; j++)
    {
        for ( i = 0; i < 900; i++)
        {
            fprintf(result,"%2d ", final_eleven[j][i]); 
        }
        fprintf(result,"\n\n");
    
    }
/*for (i=0; i<7; i++) 
         {
            free(final_eleven);
         } 
free(*final_eleven);*/
}
fclose(result);
//Highest individual run 
void mergeself(struct player A[],int l,int m,int n,struct player C[])
{
	int i=l,j=m+1,k=l;
	while(i<=m && j<=n)
	{
		if(strcmp(A[i].player_name,A[j].player_name)<=0)
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


int highest_run(struct team t[],int n)
{

	
	int i,j,k=0,runs;
    struct player a[n*15],c[n*15];				//a[] to store required players
	int max=t[0].all_players[0].previous_total_score;
    
	
	for(i=0;i<n;++i)
	{
		for(j=0;j<15;++j)
		{
			runs=t[i].all_players[j].previous_total_score;
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
    printf("Player Name(s) and runs of player scoring highest runs:");


    Mergesort(a,0,k-1,c);
  
        for(i=0;i<k;++i)
        {
            printf("\nName= %s  Runs= %ld\n",a[i].player_name,a[i].previous_total_score);
        }
    
    
	
   return a[0].player_id; 	
	
}


struct player highest_average(struct team* all_teams,int n)
{  
    
    int i,j;
    int k =0;
    float maxavg,avg[120];int mode[120];
    FILE *fp2;
    fp2=fopen("players_average.txt","r");
    for (i = 0; i < n ; i++)
    {
        for (j = 0; j < 15 ; j++)
        {
            fscanf(fp2,"%f",&avg[k]);
            all_teams[i].all_players[j].previous_avg=avg[k];
            k++;
        }
        
    }

    maxavg=avg[0];k=0;
    //INSERT MAX ELEMENT IN ARRAY ALGO HERE
   
    for(i=0;i<n;++i)
    {
        for(j=0;j<15;++j)
        {
            if(all_teams[i].all_players[j].previous_avg>=maxavg)
            {
                if(all_teams[i].all_players[j].previous_avg==maxavg)
                {
                    mode[k]=all_teams[i].all_players[j].player_id;
                    k++;
                }
                else
                {
                    k=0;
                    maxavg=all_teams[i].all_players[j].previous_avg;
                    mode[k]=all_teams[i].all_players[j].player_id;
                    k++;
                }
            }
        }
        
    }
     printf("\nMax average= %f",maxavg);  
    struct player player_highest_avg[k],temp[k];
    k=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<15;++j)
        {
            if(mode[k]==all_teams[i].all_players[j].player_id)
            {
                player_highest_avg[k]=all_teams[i].all_players[j];
                k++;
            }
           
        }
    }
    
    printf("\nPlayer(s) with highest average:\n");

    Mergesort(player_highest_avg,0,k-1,temp);
  
    for(i=0;i<k;++i)
    {
        printf("Name= %s\n",player_highest_avg[i].player_name);
    }
    fclose(fp2);
    //RETURN THE PLAYER WHICH HAS MAX AVERAGE
    return player_highest_avg[0];

}

void Init (struct team* a,int pointsTable[][2],int sz1)
{
    for(int i=0;i<sz1;i++)
    {
        pointsTable[i][1]=0;
        pointsTable[i][0]=a[i].team_id;
    }
}


void beginTournament(struct team* teams_playing,int pointsTable[][2],int sz,int groupsize,struct match_played* match)
{   
    void print4largest(int pointsTable[][2],int hi, int lo,int win[],int j);
    int i=0,j=0;int k,t=0,p,win[5];
    int ans;
    FILE* fp,*fptr,*fp1;
    fptr= fopen("name.txt","r");
    fp = fopen("presentscoreandWickets.txt","r");
    fp1=fopen("wicketsbypacers.txt","r");
    for(k=0;k<sz;k++)
            {
                for(p=0;p<15;p++)
                {
                    fscanf(fptr,"%s",teams_playing[k].all_players[p].player_name);
                    
                }
            }
    
    printf("Matches will be played now in Group 1\n");
    for(i=0;i<groupsize-1;i++)
    {
        for (j = i+1; j < groupsize; j++)
        {
            printf("Match is being played between %d and %d\n",teams_playing[i].team_id,teams_playing[j].team_id);
            t++;
            match[t-1].match_id=t;
            match[t-1].teams_played[0]=teams_playing[i];
            match[t-1].teams_played[1]=teams_playing[j];
    
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
            
           for(k=0;k<2;k++)
            {
                for(p=0;p<15;p++)
                {
                    fscanf(fp,"%d %d", &teams_playing[i].all_players[p].present_match_score,&teams_playing[i].all_players[p].present_match_wicket);
                    teams_playing[i].all_players[p].previous_total_score+=teams_playing[i].all_players[p].present_match_score;
                    teams_playing[i].all_players[p].previous_total_wickets+=teams_playing[i].all_players[p].present_match_wicket;
                    
                }
            }

            fscanf(fp1,"%d %d",&match[t-1].wicket_taken_by_pacers,&match[t-1].man_of_the_match);
            
            match[t-1].winning_team=ans;
        }
        
    }





    printf("Matches will be played now in Group 2\n");
    for(i=groupsize;i<2*groupsize-1;i++)
    {
        for (j = i+1; j < 2*groupsize; j++)
        {
            printf("Match is being played between %d and %d\n",teams_playing[i].team_id,teams_playing[j].team_id);
            t++;
            match[t-1].match_id=t;
            match[t-1].teams_played[0]=teams_playing[i];
            match[t-1].teams_played[1]=teams_playing[j];
            printf("Enter");
            printf("Who will win? Enter the id and type -1 for tie\n");
            scanf("%d",&ans);
            if(ans==-1)
            {
                for(k=0;k<2*groupsize;k++)
                {   
                    if(pointsTable[k][0]==teams_playing[i].team_id || pointsTable[k][0]==teams_playing[j].team_id)
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
            for(k=0;k<2;k++)
            {
                for(p=0;p<15;p++)
                {
                    fscanf(fp,"%d %d", &teams_playing[i].all_players[p].present_match_score,&teams_playing[i].all_players[j].present_match_wicket);
                    teams_playing[i].all_players[p].previous_total_score+=teams_playing[i].all_players[p].present_match_score;
                    teams_playing[i].all_players[p].previous_total_wickets+=teams_playing[i].all_players[p].present_match_wicket;
                }
            }
            fscanf(fp1,"%d %d",&match[t-1].wicket_taken_by_pacers,&match[t-1].man_of_the_match);
        }
        
    }
    printf("\nPoints table:");
    for(i=0;i<2*groupsize;++i)printf("\n team %d = %d",pointsTable[i][0],pointsTable[i][1]);
    printf("\n");
    print4largest(pointsTable,0,groupsize,win,0);
    print4largest(pointsTable,groupsize,2*groupsize,win,2);
    printf("Now playing knockouts...");
    
    for(i=0,j=0;i<2;++i,j+=2)
    {
        printf("Match is being played between %d and %d\n",win[j],win[j+1]);
        for(k=0;k<2;k++)
            {
                for(p=0;p<15;p++)
                {
                    fscanf(fp,"%d %d", &teams_playing[win[j]].all_players[p].present_match_score,&teams_playing[i].all_players[j].present_match_wicket);
                    teams_playing[j].all_players[p].previous_total_score+=teams_playing[j].all_players[p].present_match_score;
                    teams_playing[j].all_players[p].previous_total_wickets+=teams_playing[j].all_players[p].present_match_wicket;
                }
                j++;
            }
            j=j-2;
        t++;
        printf("Enter");
            printf("Who will win? Enter the id\n");
            scanf("%d",&ans);
            
                for(k=0;k<2*groupsize;k++)
                {   
                    if(pointsTable[k][0]==ans)
                    {
                        pointsTable[k][1]+=2;
                    }
                }
            
            fscanf(fp1,"%d %d",&match[t-1].wicket_taken_by_pacers,&match[t-1].man_of_the_match);
            match[t-1].winning_team=ans;
    }
    printf("Finals...");
    printf("Match is being played between %d and %d\n",match[t-1].winning_team,match[t-2].winning_team);
    int win1=match[t-1].winning_team;int win2=match[t-2].winning_team;
      printf("Enter");
            printf("Who will win? Enter the id\n");
            scanf("%d",&ans);
            win[4]=ans;
    
                for(p=0;p<15;p++)
                {
                    fscanf(fp,"%d %d", &teams_playing[win1].all_players[p].present_match_score,&teams_playing[win1].all_players[p].present_match_wicket);
                    teams_playing[win1].all_players[p].previous_total_score+=teams_playing[win1].all_players[p].present_match_score;
                    teams_playing[win1].all_players[p].previous_total_wickets+=teams_playing[win1].all_players[p].present_match_wicket;
                }

                for(p=0;p<15;p++)
                {
                    fscanf(fp,"%d %d", &teams_playing[win2].all_players[p].present_match_score,&teams_playing[win2].all_players[p].present_match_wicket);
                    teams_playing[win2].all_players[p].previous_total_score+=teams_playing[win2].all_players[p].present_match_score;
                    teams_playing[win2].all_players[p].previous_total_wickets+=teams_playing[win2].all_players[p].present_match_wicket;
                }
    t++;
  
            for(k=0;k<2*groupsize;k++)
                {   
                    if(pointsTable[k][0]==ans)
                    {
                        pointsTable[k][1]+=2;
                    }
                }
            
 
            fscanf(fp1,"%d %d",&match[t-1].wicket_taken_by_pacers,&match[t-1].man_of_the_match);
            match[t-1].winning_team=ans;
    
fclose(fp);
fclose(fptr);
fclose(fp1);
 //SOrt teams playing array from 0 to groupsize-1 and groupsize to n-1
 //then top 2 teams from each group would advance to the knock outs.  



}

void print4largest(int pointsTable[][2], int lo,int hi,int win[],int j) 
{ 
	int i, first, second; 
	first = second=-1;
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
            printf("point of team %d = %d \n",pointsTable[i][0],pointsTable[i][1]);
            win[j++]=pointsTable[i][0];
        }
    }
} 

//function to show players who have been man of the match atleast k times
void man_of_the_match_ktimes(struct match_played* match,struct team* teams_playing,int n)
{
    /* data */
    int k,i,m,j,total_matches=((n/2)*((n/2)-1)) +3;
    printf("\n Enter the value of k(for man of the match):");
    scanf("%d",&k);
    int man_match[total_matches][2],temp[total_matches];
    struct player p[total_matches],q[total_matches],r[total_matches];                            //man_match[][] stores man_of_the_match id and no. of times he's been declared man of the match
    man_match[0][0]=match[0].man_of_the_match;
    FILE *fp3;
    fp3=fopen("century.txt","r");
    for(i=0;i<n;++i)
    {
        for(j=0;j<15;++j)
        {
            fscanf(fp3,"%d",&teams_playing[i].all_players[j].century);
        }
        
    }
    
    for(i=0;i<total_matches;++i)
    {
        man_match[i][1]=1;
        man_match[i][0]=match[i].man_of_the_match;
	    temp[i]=match[i].man_of_the_match;
    }
    quickSort(temp,0,total_matches-1);
    for(i=0;i<total_matches;++i)
    {
        man_match[i][0]=temp[i];
    }
    for(i=0,m=1;i<total_matches-1 && m<total_matches;++i,++m)
    {
        while(man_match[i][0]==man_match[m][0])
        {
            man_match[i][1]++;
            ++m;
        }
            if (m<total_matches)
            {
                man_match[i+1][0]=man_match[m][0];
            }
            
           
    }
   
    int count=0,req_motm=i;m=0;
    while(m<req_motm)
    {
        if(man_match[m][1]>=k)
	    {     
            for(i=0;i<n;++i)
            {
                for(j=0;j<15;++j)
                {    
                    if(teams_playing[i].all_players[j].player_id==man_match[m][0])
                    {
                            p[count++]=teams_playing[i].all_players[j];
                            
                    }
                    
                }
            }
        }
	    m++;
    }
    Mergesort(p,0,count-1,q);
	printf("\nMan of the match atleast k times");
    for(i=0;i<count;++i)
    {
        printf("\n Name = %s ",p[i].player_name);
    }
   
    int max=p[0].century;k=0;
    for(i=0;i<count;++i)
    {
        if(p[i].century>=max)
			{
				if(p[i].century==max)
				{
					r[k]=p[i];
					k++;
				}
				else {
					k=0;
					max=p[i].century;
					r[k]=p[i];
					k++;
				}
            }
    }
    Mergesort(r,0,k-1,q);
    printf("\nMax no of centuries= %d by these:",max);
    for(i=0;i<k;++i)
    {
        printf("\n Name = %s ",r[i].player_name);
    }

    fclose(fp3);
}
//Function for total wickets taken by pacers 
// Concept is we add all the wickets taken by all the players and then subtract that amount by the wickets taken by pacers in each match
// we take all matches array , iterate for every wicket taken by pacer attr.

int diff_of_spinner_pacer_wickets(struct match_played* match,int n,struct team* players) //n is number of teams
{
    //i know that n*15 would be number of players
    int i,j,total_wickets=0,wickets_taken_by_pacers=0;
    int total_matches = ((n/2)*(n/2-1))+3;
    for(i=0;i<n;i++)
    {
        for(j=0;j<15;j++)
        {
            total_wickets+=players[i].all_players[j].previous_total_wickets;
        }
    }
    
    for(i=0;i<total_matches;i++)
    {
        wickets_taken_by_pacers+=match[i].wicket_taken_by_pacers;
       
    }
    int wickets_by_spinners = total_wickets-wickets_taken_by_pacers;
    return (abs(wickets_by_spinners - wickets_taken_by_pacers));
}
    
void mergeselfnames(char A[][40],int l,int m,int n,char C[][40])
{
	int i=l,j=m+1,k=l;
	while(i<=m && j<=n)
	{
		if(strcmp(A[i],A[j])<0)
			{strcpy(C[k++],A[i++]);}
		else
			strcpy(C[k++],A[j++]);
	}

	if(i<=m)
		while(i<=m)strcpy(C[k++],A[i++]);
	else
		while(j<=n)strcpy(C[k++],A[j++]);
	
	for(i=l;i<=n;++i)
		strcpy(A[i],C[i]);
	
	
}

void Mergesortnames(char A[][40],int low,int high,char C[][40])
{
	
	int i;
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		Mergesortnames(A,low,mid,C);
		Mergesortnames(A,mid+1,high,C);
		mergeselfnames(A,low,mid,high,C);
	}
}    
int max_man_of_the_match(struct match_played* match,int n,struct team* teams_playing)
{
    int i,j;
    int count=1,maxCount=1;
    int total_matches=((n/2)*(n/2-1))+3;
    int man_match[total_matches];
   
    for (i = 0; i < total_matches; i++)
    {   
        man_match[i]=match[i].man_of_the_match;  //ids stored
    }
     int mode[total_matches];int k=0;
    //now i can calculate mode of the data to find the player with max mom awards.
    quickSort(man_match,0,total_matches-1);

    for(i=0;i<total_matches-1;i++)
    {
        if(man_match[i+1]==man_match[i])
        {
            count++;
        }
        else
        {
            count=1;
        }
        if(count>=maxCount)
        {
            if(count==maxCount)
            {
                mode[k]=man_match[i];
                k++;
            }
            else
            {
                k=0;
                maxCount=count;
                mode[k]=man_match[i];
                k++;
            }
            
        }
    }
    int total=k;k=0;int l=0;
    char player_names[total][40],C[total][40];
    while(k<total)
    {
        for(i=0;i<n;++i)
        {
            for(j=0;j<15;++j)
            {
                if(mode[k]==teams_playing[i].all_players[j].player_id)
                {
                    strcpy(player_names[l++],teams_playing[i].all_players[j].player_name);
                }
            }
        
        }
    k++;
    }
    Mergesortnames(player_names,0,total-1,C);
    printf("Player ID(s) and name(s) of the Man of the Match(maximum times):\n");
    for(i=0;i<total;++i)
    {
        printf(" %d  %s\n",mode[i],player_names[i]);
    }
    return mode[0];
}

void check_mom_is_highest_run_scorer(struct match_played* match,int n,struct team* t)
{
    int highest,maxmom;
    highest = highest_run(t,n);
    maxmom = max_man_of_the_match(match,n,t);
    if(highest==maxmom)
    {
        printf("\nThe highest run scorer is also the player who has won max number of man of the match awards\n");

    }
    else{
        printf("\nThe highest run scorer and the max man of the match awardee are different\n");
    }

}


int main()
{
    int n,i,j,scene,highestRunScorer;
    struct player player;
    printf("Enter the number of teams:\n");
    scanf("%d",&n);
    int* pointsTable[2];
    int g;
    int diffWickets;
    struct team teams_playing[n];
    int groupsize=n/2;
    int total_matches=((n/2)*(n/2-1)) +3;
    struct match_played match[total_matches];
    int maxManOM;
    FILE* fp,*fp1;
    fp=fopen("ID.txt","r");
    fp1 = fopen("role.txt","r");
    if(fp==NULL || fp1==NULL)
    {
        printf("No file to read data from.1");

    } 
    else
    {
        printf("Taking Player ID's and Roles from File.\n");
        for(i=0;i<n;++i)
        {
            for(j=0;j<15;++j)
            {
                fscanf(fp1,"%s",teams_playing[i].all_players[j].player_role); 
            }
        }
        
        for(i=0;i<n;++i)
        {
            for(j=0;j<15;++j)
            {
                fscanf(fp,"%d",&teams_playing[i].all_players[j].player_id);
                teams_playing[i].all_players[j].previous_total_score=0;
                teams_playing[i].all_players[j].previous_total_wickets=0;
            }
        }
    }
        fclose(fp1);
        fclose(fp);
        fp = fopen("teamIDs.txt","r");
        if(fp==NULL)
        {
             printf("No file to read data from.");
        }
        else
        {
            //printf("Please Enter team IDs(team IDs should be like 0,1,2,...,n-1) \n");
            for (i = 0; i < n; i++)
            {
                 fscanf(fp,"%d",&teams_playing[i].team_id);
            }
        }
        fclose(fp);
        
        
        printf("What do you want to do?\n");
        
        printf("Type 1 to begin the tournament.\nType 2 to view the highest run scorer.\nType 3 to see player who was man of the match the most times.\nType 4 to see whether 2 and 3 are the same players\nType 5 to see highest averaged batsman\nType 6 to view difference between wickets taken by spinners and pacers.\nType 7 to view players who were man of the match for atleast k times.\nType 8 to view possible combinations of playing eleven\n");
        scanf("%d",&scene);
        switch (scene)
        {
        case 1:
        Init(teams_playing,pointsTable,n);
        beginTournament(teams_playing,pointsTable,n,groupsize,match);
        
     


        case 2:
        
        highestRunScorer = highest_run(teams_playing,n);
        //printf("Player with highest runs(Player ID): %d",highestRunScorer);
        
        maxManOM = max_man_of_the_match(match,n,teams_playing);
        check_mom_is_highest_run_scorer(match,n,teams_playing);
       
      
        case 5: 
             
        player=highest_average(teams_playing,n);
    
     
        

        case 6:
        
        diffWickets=diff_of_spinner_pacer_wickets(match,n,teams_playing);
        printf("Difference between no. of wickets by pacers and spinners : %d",diffWickets);
         printf("\nBreak");
      

        case 7:
        man_of_the_match_ktimes(match,teams_playing,n);
        
        
        case 8:
        
        printf("\nEnter the team id whose all possible combinations of playing eleven you want to have a look at(0-n) :\n");
        scanf("%d",&g);
        playing_eleven(teams_playing[g]);
        break;
        
    
    
    }
return 0;
}

