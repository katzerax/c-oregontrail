// this is a re-implementation of the original Oregon Trail source code into C.
// this is an initial draft & contains minimal changes to the fundamental logic
// of the original game. it is therefore NOT well optimized, that part is for
// later iterations of this project.
// - K 

#include <stdio.h>
#include <string.h>

int main() {
    // 160 PRINT "DO YOU NEED INSTRUCTIONS  (YES/NO)";
    printf("DO YOU NEED INSTRUCTIONS  (YES/NO)\n");
    char yesNo[5]; //C$ == yesNo
    scanf("%s", yesNo);
    // INSTRUCTIONS
    if(strcmp(yesNo, "NO")!=0){
        printf("THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM\n");
        printf("INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847.\n");
        printf("YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL\n");
        printf("IN 5-6 MONTHS --- IF YOU MAKE IT ALIVE.\n\n");
        printf("YOU HAD SAVED $900 TO SPEND FOR THE TRIP, AND YOU'VE JUST\n");
        printf("   PAID $200 FOR A WAGON.\n");
        printf("YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE\n");
        printf("   FOLLOWING ITEMS:\n\n");
        printf("     OXEN - YOU CAN SPEND $200-$300 ON YOUR TEAM\n");
        printf("               BECAUSE YOU'LL HAVE BETTER ANIMALS\n\n");
        printf("     FOOD - THE MORE YOU HAVE, THE LESS CHANCE THERE\n");
        printf("               IS OF GETTING SICK\n\n");
        printf("     AMMUNITION - $1 BUYS A BELT OF 50 BULLETS\n");
        printf("            YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS\n");
        printf("               AND BANDITS, AND FOR HUNTING FOOD\n\n");
        printf("     CLOTHING - THIS IS ESPECIALLY IMPORTANT FOR THE COLD\n");
        printf("               WEATHER YOU WILL ENCOUNTER WHEN CROSSING\n");
        printf("               THE MOUNTAINS\n\n");
        printf("     MISCELLANEOUS SUPPLIES - THIS INCLUDES MEDICINE AND\n");
        printf("               OTHER THINGS YOU WILL NEED FOR SICKNESS\n");
        printf("               AND EMERGENCY REPAIRS\n\n\n");
        printf("YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP -\n");
        printf("OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG\n");
        printf("THE WAY WHEN YOU RUN LOW. HOWEVER, ITEMS COST MORE AT\n");
        printf("THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET\n");
        printf("MORE FOOD.\n");
        printf("WHENEVER YOU HAVE TO USE YOUR TRUSTY RIFLE ALONG THE WAY,\n");
        printf("YOU WILL BE TOLD TO TYPE IN A WORD (ONE THAT SOUNDS LIKE A\n");
        printf("GUN SHOT). THE FASTER YOU TYPE IN THAT WORD AND HIT THE\n");
        printf("\"\"RETURN\"\" KEY, THE BETTER LUCK YOU'LL HAVE WITH YOUR GUN.\n\n");
        printf("AT EACH TURN, ALL ITEMS ARE SHOWN IN DOLLAR AMOUNTS\n");
        printf("EXCEPT BULLETS\n");
        printf("WHEN ASKED TO ENTER MONEY AMOUNTS, DON'T USE A \"\"$\"\".\n\n");
        printf("GOOD LUCK!!!\n\n\n");
    }
    //690 below. selecting NO skips to this in the original code. the original idea is Anything other than NO prints instructions.

    printf("HOW GOOD A SHOT ARE YOU WITH YOUR RIFLE?\n");
    printf("  (1) ACE MARKSMAN,  (2) GOOD SHOT,  (3) FAIR TO MIDDLIN'\n");
    printf("         (4) NEED MORE PRACTICE,  (5) SHAKY KNEES\n");
    printf("ENTER ONE OF THE ABOVE -- THE BETTER YOU CLAIM YOU ARE, THE\n");
    printf("FASTER YOU'LL HAVE TO BE WITH YOUR GUN TO BE SUCCESSFUL.\n");

    int shootingExpertise; // shootingExpertise == D9 ~760.
    scanf("%d", &shootingExpertise);
    if(shootingExpertise>5){
        shootingExpertise = 0; // currently unclear if this means claimed low skill deletes skill calculations, or makes it really hard
    }
    //printf("%d", shootingExpertise); // debug

    // 800 REM ***INITIAL PURCHASES***
    int fortFlag = -1; //810 fortFlag == X1, -1
    int injuryFlag, illnessFlag, southPassClearFlag, blueMountainsClearFlag, totalTripMileage, southPassClearInSettingMileageFlag, turnNumberDateSet;// 820 K8=S4=F1=F2=M=M9=D3=0
    injuryFlag = illnessFlag = southPassClearFlag = blueMountainsClearFlag = totalTripMileage = southPassClearInSettingMileageFlag = turnNumberDateSet = 0;
    /*  
        injuryFlag == K8 
        illnessFlag == S4
        southPassClearFlag == F1
        blueMountainsClearFlag == F2
        totalTripMileage == M
        southPassClearInSettingMileageFlag == M9 FLAG FOR CLEARING SOUTH PASS IN SETTING MILEAGE [???]
        turnNumberDateSet == D3 TURN NUMBER FOR SETTING DATE
    */
    printf("\n\n");
    int animalSpending; // animalSpending == A.
    while(1){
        printf("HOW MUCH DO YOU WANT TO SPEND ON YOUR OXEN TEAM\n"); // 850
        // 860 INPUT A - "amount spent on animals"
        scanf("%d", &animalSpending);

        if(animalSpending<200){
            printf("NOT ENOUGH\n");
        }
        else if(animalSpending>300){
            printf("TOO MUCH\n");
        }
        else if(animalSpending>=200 && animalSpending<=300){
            break;
        }
    } // end 920

// 930 PRINT "HOW MUCH DO YOU WANT TO SPEND ON FOOD";
    int foodSpending; // foodSpending == F.
    while(1){
        printf("HOW MUCH DO YOU WANT TO SPEND ON FOOD\n"); // 930
        scanf("%d", &foodSpending);
        if(foodSpending<=0){
            printf("IMPOSSIBLE\n");
        }
        else if(foodSpending>0){
            break;
        }
    } // end 970





    
    //printf("\n");
    return 0;
}

// 930 PRINT "HOW MUCH DO YOU WANT TO SPEND ON FOOD";
// 940 INPUT F
// 950 IF F >= 0 THEN 980
// 960 PRINT "IMPOSSIBLE"
// 970 GOTO 930

// --------------------------
// printf("\n");
// 6470 REM ***IDENDIFICATION OF VARIABLES IN THE PROGRAM***
// 6480 REM A = AMOUNT SPENT ON ANIMALS
// 6490 REM B = AMOUNT SPENT ON AMMUNITION
// 6500 REM B1 = ACTUAL RESPONSE TIME FOR INPUTTING "BANG"
// 6510 REM B3 = CLOCK TIME AT START OF INPUTTING "BANG"
// 6520 REM C = AMOUNT SPENT ON CLOTHING
// 6530 REM C1 = FLAG FOR INSUFFICIENT CLOTHING IN COLD WEATHER
// 6540 REM C$ = YES/NO RESPONSE TO QUESTIONS -> yesNo
// 6550 REM D1 = COUNTER IN GENERATING EVENTS
// 6560 REM D3 = TURN NUMBER FOR SETTING DATE
// 6570 REM D4 = CURRENT DATE
// 6580 REM D9 = CHOICE OF SHOOTING EXPERTISE LEVEL
// 6590 REM E = CHOICE OF EATING
// 6600 REM F = AMOUNT SPENT ON FOOD
// 6610 REM F1 = FLAG FOR CLEARING SOUTH PASS
// 6620 REM F2 = FLAG FOR CLEARING BLUE MOUNTAINS
// 6630 REM F9 = FRACTION OF 2 WEEKS TRAVELED ON FINAL TURN
// 6640 REM K8 = FLAG FOR INJURY
// 6650 REM L1 = FLAG FOR BLIZZARD
// 6660 REM M = TOTAL MILEAGE WHOLE TRIP
// 6670 REM M1 = AMOUNT SPENT ON MISCELLANEOUS SUPPLIES
// 6680 REM M2 = TOTAL MILEAGE UP THROUGH PREVIOUS TURN
// 6690 REM M9 = FLAG FOR CLEARING SOUTH PASS IN SETTING MILEAGE
// 6700 REM P = AMOUNT SPENT ON ITEMS AT FORT
// 6710 REM R1 = RANDOM NUMBER IN CHOOSING EVENTS
// 6720 REM S4 = FLAG FOR ILLNESS
// 6730 REM S5 = ""HOSTILITY OF RIDERS"" FACTOR
// 6740 REM S6 = SHOOTING WORD SELECTOR
// 6750 REM S$ = VARIATIONS OF SHOOTING WORD
// 6760 REM T = CASH LEFT OVER AFTER INITIAL PURCHASES
// 6770 REM T1 = CHOICE OF TACTICS WHEN ATTACKED
// 6780 REM X = CHOICE OF ACTION FOR EACH TURN
// 6790 REM X1 = FLAG FOR FORT OPTION
// 6800 END