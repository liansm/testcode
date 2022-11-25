#include <stdio.h>
#include <math.h>
#include <random>
using namespace std;

float cal_stand_diff(int match_ages[], float avg_age, int num)
{
  float total = 0;
  for(int i = 0; i < num; ++i){
    total += (match_ages[i] - avg_age) * (match_ages[i] - avg_age);
  } 

  return sqrt(total/num);
}


void print_match_age(int match_ages[], int num, float cur_total_age, float s_diff)
{
  printf("[avg=%f][s_diff=%f] ", cur_total_age/num, s_diff);
  for(int i = 0; i < num; ++i){
    printf("%d ", match_ages[i]); 
  }
  printf("\n");
}



void find_match_age(int min_age, int max_age, float avg_age, float s_diff, int num)
{
  default_random_engine e;
  uniform_int_distribution<unsigned> random_age(min_age, max_age);
  float total_age = avg_age * num;
  int match_ages[num];
  while(true){
    int cur_total_age = 0;
    for(int i = 0; i < num-1; ++i){
      match_ages[i] = random_age(e);
      cur_total_age += match_ages[i];
    }

    if(cur_total_age + min_age <= total_age && cur_total_age + max_age > total_age){
      match_ages[num-1] = round(total_age - cur_total_age);
      cur_total_age += match_ages[num-1];
      float cur_s_diff = cal_stand_diff(match_ages, avg_age, num);
      
      if(fabs(s_diff - cur_s_diff) <= 0.01){
        print_match_age(match_ages, num, cur_total_age, cur_s_diff);
//        return;
      }
    }
    else{
      continue;
    }
  }
}


int main(int argc, char ** argv)
{
  if(argc != 6){
    printf("Usage: ./find_match_age min_age max_age avg_age s_diff num\n");
    exit(-1);
  }


  int min_age = atoi(argv[1]);
  int max_age = atoi(argv[2]);
  float avg_age = atof(argv[3]);
  float s_diff = atof(argv[4]);
  int num = atoi(argv[5]);

  find_match_age(min_age, max_age, avg_age, s_diff, num);

  

}




