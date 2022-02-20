#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h> 

int i,j;
int state, back, district, cases, zone, choose, hotline_selection, clinic_state_hotline;
int main_exit;
void menu();
void close();
char choice1, choice2, choice3, choice4, choice5;
int district_Johor;
bool otheroption;
void account_settings();
void additional_resources();
void sop();
void dir_helpdesklink();
void digital_healthcare();

struct date
{
    int day,month,year;
};

struct 
{
    char name[60];
    int ic_no1,ic_no2,ic_no3,age,relation;
    char gender;
    char address[60];
    int postcode;
    double phone;
    struct date dob;
}add,upd,check,rem;

void fordelay(int j)
{   
	int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc() //Registration for new user
{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    ic_no:
    system("cls");
    	printf("\n\n\n\n\t\t\tLOADING REGISTRATION");
        	for(i=0;i<=6;i++)
        	{
	            fordelay(100000000);
	            printf(".");
       		}
    system("cls");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\ NEW USER REGISTRATION \xB2\xB2\xB2\xB2\n");
    printf("\nEnter your IC Number(XXXXXX-XX-XXXX): ");
    scanf("%d-%d-%d",&check.ic_no1,&check.ic_no2,check.ic_no3);
    while(fscanf(ptr,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf",&add.ic_no1,&add.ic_no2,&add.ic_no3,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.relation,&add.age,add.gender,add.address,&add.postcode,&add.phone)!=EOF)
    {
        if (check.ic_no1==add.ic_no1 && check.ic_no2==add.ic_no2 && check.ic_no3==add.ic_no3)
            {
				printf("IC no. already existed!");
	            fordelay(1000000000);
	                goto ic_no;
            }
    }
    add.ic_no1=check.ic_no1;
    add.ic_no2=check.ic_no2;
    add.ic_no3=check.ic_no3;
    printf("\nEnter your name: ");
    scanf(" %[^\n]s",add.name);
    printf("\nEnter your date of birth(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter the age: ");
    scanf("%d",&add.age);
    gender:
	printf("\nWhat is your gender?\n");
	printf("Enter 'M' for MALE or 'F' for FEMALE.\n");
    scanf(" %s",&add.gender);
    while (add.gender != 'M' && add.gender != 'F'){
	    printf("Error! Please enter again!\n");
		goto gender;
	}
    printf("\nEnter FULL address: ");
    scanf(" %[^\n]s",add.address);
    printf("\nEnter the postcode: ");
    scanf("%d",&add.postcode);
    printf("\nEnter your phone number: ");
    scanf("%lf",&add.phone);

    	fprintf(ptr,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf \n",add.ic_no1,add.ic_no2,add.ic_no3,add.name,add.dob.day,add.dob.month,add.dob.year,add.relation,add.age,add.gender,add.address,add.postcode,add.phone);

    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
		{
    		close();
		}   
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

void edit_acc(void) //Update Account Information
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\ UPDATE YOUR INFORMATION \xB2\xB2\xB2\xB2\n");
    printf("\nEnter the IC No. of the user whose info you want to update(XXXXXX-XX-XXXX): ");
    scanf("%d-%d-%d",&upd.ic_no1,&upd.ic_no2,&upd.ic_no3);
    while(fscanf(old,"%d-%d-%d %[^\n]s %d/%d/%d %d %d %s %s %d %lf",&add.ic_no1,&add.ic_no2,&add.ic_no3,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.relation,&add.age,add.gender,add.address,&add.postcode,&add.phone)!=EOF)
    {
        if (add.ic_no1==upd.ic_no1 && add.ic_no2==upd.ic_no2 && add.ic_no3==upd.ic_no3)
        {  
			test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone): ");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
					printf("Enter the new address: ");
	                scanf(" %[^\n]s",upd.address);
	                fprintf(newrec,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf\n",add.ic_no1,add.ic_no2,add.ic_no3,add.name,add.dob.day,add.dob.month,add.dob.year,add.relation,add.age,add.gender,upd.address,add.postcode,add.phone);
	                system("cls");
	                printf("Changes saved!");
                }
            else if(choice==2)
                {
	                printf("Enter the new phone number: ");
	                scanf("%lf",&upd.phone);
	                fprintf(newrec,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf\n",add.ic_no1,add.ic_no2,add.ic_no3,add.name,add.dob.day,add.dob.month,add.dob.year,add.relation,add.age,add.gender,add.address,add.postcode,upd.phone);
	                system("cls");
	                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf\n",add.ic_no1,add.ic_no2,add.ic_no3,add.name,add.dob.day,add.dob.month,add.dob.year,add.relation,add.age,add.gender,add.address,add.postcode,add.phone);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

	if(test!=1){   
			system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit_acc();
                else
                    {
						printf("\nInvalid!\a");
                    	goto edit_invalid;
					}
        }
    	else{
		printf("\n\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void check_in() //Check-in
{
	printf("\n\n\n\n\t\t\tLOADING CHECK-IN");
        	for(i=0;i<=6;i++)
        	{
	            fordelay(100000000);
	            printf(".");
       		}
    system("cls");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\ CHECK-IN \xB2\xB2\xB2\xB2\n\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("|  NO  | STATE             |  NO  | STATE            |  NO  | STATE          |  NO  | STATE          |\n");
    printf("|------|-------------------|------|------------------|------|----------------|------|----------------|\n");
    printf("|  1.  | Johor             |  2.  | Kedah            |  3.  | Kelantan       |  4.  | Melaka         |\n");
    printf("|  5.  | Negeri Sembilan   |  6.  | Pahang           |  7.  | Penang         |  8.  | Perak          |\n");
    printf("|  9.  | Perlis            |  10. | Sabah            |  11. | Sarawak        |  12. | Selangor       |\n");
    printf("|  13. | Terengganu        |  14. | Kuala Lumpur     |  15. | Labuan         |  16. | Putrajaya      |\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf(" 0. Main Menu\n");
    printf("Please choose your state: ");
    scanf("%d", &state);
    while (state < 0 || state > 16)
	{
      printf("Error! Please re-enter your choice: \n");
      scanf("%d",&state);
    }
    if (state == 0){
    	menu();
	}
}

void state_district() //Choose District
{
    switch(state){
    	case 1: 
			printf("\n************************************* STATE / NEGERI : JOHOR *************************************\n");
			printf("   --------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Johor Bahru        4.  Kulai                 7.  Segamat             10.  Mersing   |\n");
			printf("   |  2.  Batu Pahat         5.  Muar                  8.  Pontian                            |\n"); 
			printf("   |  3.  Kluang             6.  Kota Tinggi           9.  Tangkak                            |\n");
    		printf("   --------------------------------------------------------------------------------------------\n");
    		printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;
			
		case 2:
			printf("\n**************************************** STATE / NEGERI : KEDAH ****************************************\n");
			printf("   --------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kuala Muda          4.  Kubang Pasu          7.  Langkawi            10.  Padang Terap    |\n");
			printf("   |  2.  Kota Setar          5.  Baling               8.  Yan                 11.  Pokok Sena      |\n");
			printf("   |  3.  Kulim               6.  Pendang              9.  Sik                 12.  Bandar Baharu   |\n");
			printf("   --------------------------------------------------------------------------------------------------\n");	
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;
	
		case 3:
			printf("\n*********************************** STATE / NEGERI : KELANTAN ***********************************\n");
			printf("   -------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kota Bharu          4.  Bachok               7.  Kuala Krai          10.  Jeli     |\n");
			printf("   |  2.  Pasir Mas           5.  Tanah Merah          8.  Machang                           |\n");
			printf("   |  3.  Tumpat              6.  Pasir Puteh          9.  Gua Musang                        |\n");
			printf("   -------------------------------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;
	
	  	case 4:
			printf("\n************************ STATE / NEGERI : MELAKA ************************\n");
			printf("   -------------------------------------------------------------------\n");
			printf("   |  1.  Melaka Tengah        2.  Alor Gajah            3.  Jasin   |\n");
			printf("   -------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;

	  	case 5:
			printf("\n******************************** STATE / NEGERI : NEGERI SEMBILAN *******************************\n");
	  		printf("   -------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Seremban           3.  Port Dickson          5.  Kuala Pilah          7.  Jelebu   |\n");
			printf("   |  2.  Jempol             4.  Tampin                6.  Rembau                            |\n");
			printf("   -------------------------------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;

	  	case 6:
			printf("\n**************************************** STATE / NEGERI : PAHANG ********************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kuantan            4.  Maran                 7.  Bera                 10.  Lipis               |\n");
			printf("   |  2.  Temerloh           5.  Rompin                8.  Raub                 11.  Cameron Highlands   |\n");
			printf("   |  3.  Bentong            6.  Pekan                 9.  Jerantut                                      |\n");
			printf("   -------------------------------------------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;
	
	  	case 7:
			printf("\n******************************************* STATE / NEGERI : PENANG **********************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Timur Laut Pulau Pinang           3.  Seberang Perai Utara             5.  Seberang Perai Selatan   |\n");
			printf("   |  2.  Seberang Perai Tengah             4.  Barat Daya Pulau Pinang                                       |\n");
			printf("   ------------------------------------------------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;

	  	case 8:
			printf("\n********************************************** STATE / NEGERI : PERAK *************************************************\n");
	  		printf("   -----------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kinta                          4.  Hilir Perak            7.  Kuala Kangsar            10.  Kampar       |\n");
			printf("   |  2.  Larut, Matang dan Selama       5.  Kerian                 8.  Perak Tengah             11.  Muallim      |\n");
			printf("   |  3.  Manjung                        6.  Batang Padang          9.  Hulu Perak               12.  Bagan Datuk  |\n");
			printf("   -----------------------------------------------------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;
			
	  	case 10:
			printf("\n************************************************ STATE / NEGERI : SABAH ***************************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kota Kinabalu        6.  Kinabatangan       11.  Tuaran              16.  Beaufort         21.  Tambunan     |\n");
			printf("   |  2.  Tawau                7.  Semporna           12.  Ranau               17.  Kunak            22.  Tongod       |\n");
			printf("   |  3.  Sandakan             8.  Papar              13.  Kota Belud          18.  Tenom            23.  Sipitang     |\n");
			printf("   |  4.  Lahad Datu           9.  Penampang          14.  Kudat               19.  Putatan          24.  Nabawan      |\n");
			printf("   |  5.  Keningau            10.  Beluran            15.  Kota Marudu         20.  Pitas            25.  Kuala Penyu  |\n");
			printf("   ---------------------------------------------------------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;

	  	case 11:
			printf("\n*********************************** STATE / NEGERI : SARAWAK **************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kuching             4.  Bintulu              7.  Sri Aman           10.  Kapit     |\n");
			printf("   |  2.  Miri                5.  Serian               8.  Betong             11.  Limbang   |\n");
			printf("   |  3.  Sibu                6.  Samarahan            9.  Sarikei            12.  Mukah     |\n");
			printf("   -------------------------------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;

		case 12:
			printf("\n********************************************* STATE / NEGERI : SELANGOR ************************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Petaling           3.  Klang           5.  Kuala Langat       7.  Kuala Selangor       9.  Sabak Bernam   |\n");
			printf("   |  2.  Hulu Langat        4.  Gombak          6.  Sepang             8.  Hulu Selangor                           |\n");
			printf("   ------------------------------------------------------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
    		break;

	  	case 13:
			printf("\n************************************** STATE / NEGERI : TERENGGANU ******************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kuala Terengganu         3.  Dungun            5.  Marang                    7.  Setiu         |\n");
			printf("   |  2.  Kemaman                  4.  Besut             6.  Hulu Terengganu           8.  Kuala Nerus   |\n");
			printf("   -------------------------------------------------------------------------------------------------------\n");   		
    		printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
			break;
			
		case 14:
			printf("\n***************************************** STATE / NEGERI : KUALA LUMPUR *********************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kepong              2.  Lembah Pantai                3.  Titiwangsa               4.  Cheras           |\n");
			printf("   ---------------------------------------------------------------------------------------------------------------\n");
			printf("\nPlease choose your district / Sila pilih daerah anda: ");
    		scanf("%d", &district);
			break;
    }
    	
    while ((state == 1 && district < 1) || (state == 1 && district > 10)||(state == 2 && district < 1) || (state == 2 && district > 12)||
			(state == 3 && district < 1) || (state == 3 && district > 10)||(state == 4 && district < 1) || (state == 4 && district > 3)||
			(state == 5 && district < 1) || (state == 5 && district > 7)||(state == 6 && district < 1) || (state == 6 && district > 11)||
			(state == 7 && district < 1) || (state == 7 && district > 5)||(state == 8 && district < 1) || (state == 8 && district > 12)||
			(state == 10 && district < 1) || (state == 10 && district > 25)||(state == 11 && district < 1) || (state == 11 && district > 12)||
			(state == 12 && district < 1) || (state == 12 && district > 9)||(state == 13 && district < 1) || (state == 13 && district > 8)||
			(state == 14 && district < 1) || (state == 14 && district > 4)){
      		printf("Error! Please re-enter your choice: \n");
      		scanf("%d",&district);
	}
}

void case_Johor() //Johor cases
{
	int a, b;
	int cases[10][14] =
	//  1    2	   3     4	   5	6	 7	  8    9   10	11	 12	  13   14		
	{{ 229,  27, 601,  682,    0,   0, 612,  -1,  -1,  -1,  -1,  -1,  -1,  -1},		// Johor Bahru
	 { 158, 101,  23,   11,    7,   9,   2,   5,   0,   7,  10,  11,  15,   0},		// Batu Pahat 
	 {   9, 202,   1,    1,   11,  25,   6,   0,  -1,  -1,  -1,  -1,  -1,  -1},		// Kluang 
	 {1013, 190,  11,    5,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},		// Kulai 
	 {   2,   5,  21,    3, 1607,  18,   9, 159,   4,  42,  36,   1,  -1,  -1},		// Muar 
	 { 136,  81,  26,   32,    0,   6,  31,  10,  33,   6,  -1,  -1,  -1,  -1},		// Kota Tinggi  
	 {   0,   1,   1,    1,    2,   0,  16,  19,   5,   0,   8,  -1,  -1,  -1},		// Segamat
	 {  37,  51,   4,   14,    9,  23,   0,  53,  93,   4,  -1,  -1,  -1,  -1},		// Pontian
	 {   0,   1,   5,    0,    4,   2,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},		// Tangkak 
	 {  10,   11,  0,   22,    0,   0,   2,  36,   1,   0,  -1,  -1,  -1,  -1}};	// Mersing 
	 	
	if(state==1){
		if (district==1){
			printf("\n\n******************************* DISTRICT / DAERAH : JOHOR BAHRU **********************************\n");
	  		printf("   --------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bandar            3.  Plentong            5.  Sg.Tiram                  7.  Terbau  |\n");
			printf("   |  2.  Jelutong          4.  Pulai               6.  Tanjung Kupang                        |\n");
			printf("   --------------------------------------------------------------------------------------------\n");
		}
				
		else if (district==2){
			printf("\n\n******************************************** DISTRICT / DAERAH : BATU PAHAT *********************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Sri Gading         4.  Peserai             7.  Bagan         10.  Minyak Beku       13.  Tanjong Sembrong  |\n");
			printf("   |  2.  Simpang Kanan      5.  Simpang Kiri        8.  Linau         11.  Sri Medan         14.  Chaah Baru        |\n");
			printf("   |  3.  Kg.Bahru           6.  Sg.Kluang           9.  Lubok         12.  Sg Punggor                               |\n");
			printf("   -------------------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==3){
			printf("\n\n******************************* DISTRICT / DAERAH : KLUANG *********************************\n");
	  		printf("   --------------------------------------------------------------------------------------\n");
			printf("   |  1.  Ulu Benut        3.  Macap            5.  Paloh            7.  Layang-Layang  |\n");
			printf("   |  2.  Kluang           4.  Kahang           6.  Renggam          8.  Niyor          |\n");
			printf("   --------------------------------------------------------------------------------------\n");
		}
				
		else if (district==4){
			printf("\n\n****************************** DISTRICT / DAERAH : KULAI ******************************\n");
	  		printf("   ---------------------------------------------------------------------------------\n");
			printf("   |  1.  Senai          2.  Kulai           3.  Sedenak           4.  Bukit Batu  |\n");
			printf("   ---------------------------------------------------------------------------------\n");
		}
		
		else if (district==5){
			printf("\n\n************************************ DISTRICT / DAERAH : MUAR **************************************\n");
	  		printf("   -----------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bukit Kepong         4.  Ayer Hitam            7.  Bakri             10.  Pt.Jawa      |\n");
			printf("   |  2.  Lenga                5.  Sg.Raya               8.  Bandar            11.  Sri Menanti  |\n");
			printf("   |  3.  Jorak                6.  Sg.Terap              9.  Pt.Bakar          12.  Sg.Balang    |\n");
			printf("   -----------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==6){
			printf("\n\n********************************************* DISTRICT / DAERAH : KOTA TINGGI ***********************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kota Tinggi       3.  Johor Lama        5.  Kambau                    7.  Ulu Sg.Johor        9.  Sedili Kecil  |\n");
			printf("   |  2.  Pengerang         4.  Tg.Surat          6.  Ulu Sg.Sedili Besar       8.  Sedili Besar       10.  Pantai Timur  |\n");
			printf("   ------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==7){
			printf("\n\n********************************** DISTRICT / DAERAH : SEGAMAT *************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bekok                4.  Gemas               7.  Jementah            10.  Sermin      |\n");
			printf("   |  2.  Buloh Kasap          5.  Gemereh             8.  Labis               11.  Sg.Segamat  |\n");
			printf("   |  3.  Chaah                6.  Jabi                9.  Pogoh                                |\n");
			printf("   ----------------------------------------------------------------------------------------------\n");
		}
			
		else if (district==8){
			printf("\n\n****************************************** DISTRICT / DAERAH : PONTIAN ********************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Pontian                          4.  Benut                  7.  Sg.Karang           10.  Sg.Pinggan  |\n");
			printf("   |  2.  Pengkalan Raja/Jeram Batu        5.  Rimba Terjun           8.  Ayer Masin                           |\n");
			printf("   |  3.  Ayer Baloi                       6.  Api-Api                9.  Serkat                               |\n");
			printf("   -------------------------------------------------------------------------------------------------------------\n");
		}
			
		else if (district==9){
			printf("\n\n************************ DISTRICT / DAERAH : TANGKAK **************************\n");
	  		printf("   --------------------------------------------------------------------------\n");
			printf("   |  1.  Bukit Serampang           3.  Kesang                5.  Serom     |\n");
			printf("   |  2.  Grisek                    4.  Kundang               6.  Tangkak   |\n");
			printf("   --------------------------------------------------------------------------\n");
		}
			
		else if (district==10){
			printf("\n\n********************************** DISTRICT / DAERAH : MERSING ************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Padang Endau          4.  Mersing                7.  Sembrong           10.  Triang  |\n");
			printf("   |  2.  Jemaluang             5.  Penyabong              8.  Tenggaroh                       |\n");
			printf("   |  3.  Lenggor               6.  Pulau-Pulau            9.  Tenglu                          |\n");
			printf("   ---------------------------------------------------------------------------------------------\n");
		}
	
	printf("\nPlease choose your zone: ");
	scanf("%d", &zone);	
		
    while  ((district == 1 && zone < 1) || (district == 1 && zone > 7)||(district == 2 && zone < 1) || (district == 2 && zone > 14)||
			(district == 3 && zone < 1) || (district == 3 && zone > 8)||(district == 4 && zone < 1) || (district == 4 && zone > 4)||
			(district == 5 && zone < 1) || (district == 5 && zone > 12)||(district == 6 && zone < 1) || (district == 6 && zone > 10)||
			(district == 7 && zone < 1) || (district == 7 && zone > 11)||(district == 8 && zone < 1) || (district == 8 && zone > 10)||
			(district == 9 && zone < 1) || (district == 9 && zone > 6)||(district == 10 && zone < 1) || (district == 10 && zone > 10)){
      		printf("Error! Please re-enter your choice: ");
      		scanf("%d",&zone);
	}
	
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
		}
	 	 	
		else if (cases[a-1][b-1] > 0){
			printf("\n\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}

}

void case_Kedah() //Kedah cases
{
	int a, b;
	int cases[12][28] =
	//   1	  2	   3	4	 5	   6	7	 8	  9	  10   11	12	 13	  14   15	16	 17   18   19   20   21   22   23   24   25   26   27   28
	{{ 978,  29,   5,   7,  31,   28,   5,   3,  18,  17,   1,   0,  11,   5,   6,   3,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Kuala Muda
	 {  35,  22,  23,  51,   0, 1369,  68,  17,  46,  50,   1,   5,   5,   5,  13,  24,   4,   0,   2,   0,   0,   7,   5,   4,  18,  27,   3,  12},	// Kota Setar 
	 {  43,  63,  60,  55,  51,  182,   5,   3,   0,  13,  28,  23, 229,   9,   1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Kulim
	 {  65,  16,  12,  30,  20,    7,   1,  11,   8,   9,   0,   1,   1,   2,  11,  15,  10,   0,  12,  12,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Kubang Pasu 
	 {   7,   4,   8,  90,  93,    1,  83,   7,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Baling 
	 {  13,   6,   0,  13,  29,    0,  21,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Pendang  
	 {   9,   5,   4,   0,   0,    5,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Langkawi
	 {  34,   3,  12,  10,   0,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Yan
	 {  15,   9,  24,  14,  -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Sik 
	 {   1,   1,   0,  32,   0,    0,   0,   4,   0,   4,   0,  18,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Padang Terap 
	 { 533,  13,   3,   0,   2,    0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Pokok Sena
	 {  16,   2,   0,  11,   2,    0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}};	// Bandar Baharu
	 
	 if(state==2){
		if (district==1){
			printf("\n\n************************************** DISTRICT / DAERAH : KUALA MUDA ****************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Sg.Petani             5.  Semeling              9.  Sg.Pasir                 13.  Simpor         |\n");
			printf("   |  2.  Bujang                6.  Gurun                10.  Pekula                   14.  Kuala          |\n");
			printf("   |  3.  Merbok                7.  Teloi Kiri           11.  Rantau Panjang           15.  Haji Kudong    |\n");
			printf("   |  4.  Pinang Tunggal        8.  Sidam Kiri           12.  Kota                     16.  Bukit Meriam   |\n");
			printf("   ---------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==2){
			printf("\n\n************************************* DISTRICT / DAERAH : KOTA SETAR ***************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------- \n");
			printf("   |  1.  Langgar              8.  Titi Gajah              15.  Pumpong            22.  Kangkong        |\n");
			printf("   |  2.  Bkt. Pinang          9.  Alor Malai              16.  Derga              23.  Lepai           |\n");
			printf("   |  3.  Gunung              10.  P'gkln Kundor           17.  Tajar              24.  Hutan Kampong   |\n");
			printf("   |  4.  Kuala Kedah         11.  Padang Lalang           18.  Limbong            25.  Alor Merah      |\n");
			printf("   |  5.  Sg.Baru             12.  Kubang Rotan            19.  Tebengau           26.  Anak Bukit      |\n");
			printf("   |  6.  Kota Setar          13.  Teluk Cengai            20.  Telaga Mas         27.  Sala Kechik     |\n");
			printf("   |  7.  Mergong             14.  Teluk Kechai            21.  Lengkus            28.  Padang Hang     |\n");
			printf("   -----------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==3){
			printf("\n\n************************************* DISTRICT / DAERAH : KULIM ***************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Karangan             5.  Keladi              9.  Sedim                 13.  Sg Seluang   |\n");
			printf("   |  2.  Lunas                6.  Kulim              10.  Bagan Sena            14.  Sungai Ular  |\n");
			printf("   |  3.  Padang Cina          7.  Junjong            11.  Padang Meha           15.  Mahang       |\n");
			printf("   |  4.  Naga Lilit           8.  Terap              12.  Sidam Kanan                             |\n");
			printf("   -------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==4){
			printf("\n\n******************************************* DISTRICT / DAERAH : KUBANG PASU *********************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Temin               6.  Sg Laka           11.  Kubang Pasu           16.  Jeram           21.  Wang Tepus  |\n");
			printf("   |  2.  Hosba               7.  Kepelu            12.  Padang Perahu         17.  Jerlun                           |\n");
			printf("   |  3.  Bukit Tinggi        8.  Pering            13.  Tunjang               18.  Sanglang                         |\n");
			printf("   |  4.  Jitra               9.  Ah                14.  Binjal                19.  Pelubang                         |\n");
			printf("   |  5.  Naga               10.  Putat             15.  Gelong                20.  Malau                            |\n");
			printf("   -------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==5){
			printf("\n\n***************************** DISTRICT / DAERAH : BALING *******************************\n");
	  		printf("   ----------------------------------------------------------------------------------\n");
			printf("   |  1.  Teloi Kanan        3.  Baling           5.  Kupang            7.  Tawar   |\n");
			printf("   |  2.  Bongor             4.  Pulai            6.  Siong             8.  Bakai   |\n");
			printf("   ----------------------------------------------------------------------------------\n");
		}
		
		else if (district==6){
			printf("\n\n******************************** DISTRICT / DAERAH : PENDANG **********************************\n");
	  		printf("   -----------------------------------------------------------------------------------------\n");
			printf("   |  1.  Gua Kepayang        3.  Tobiar           5.  Ayer Puteh         7.  Pdg Kerbau   |\n");
			printf("   |  2.  Bukit Raya          4.  Pdg Pusing       6.  Rambai             8.  Pdg Peliang  |\n");
			printf("   -----------------------------------------------------------------------------------------\n");
		}
		
		else if (district==7){
			printf("\n\n*********************** DISTRICT / DAERAH : LANGKAWI ************************\n");
	  		printf("   -----------------------------------------------------------------------\n");
			printf("   |  1.  Ulu Melaka         3.  Kedawang                 5.  Bohor      |\n");
			printf("   |  2.  Kuah               4.  Padang Matsirat          6. Air Hangat  |\n");
			printf("   -----------------------------------------------------------------------\n");
		}
		
		else if (district==8){
			printf("\n\n************************************ DISTRICT / DAERAH : YAN **************************************\n");
			printf("   ---------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Sala Besar       2.  Dulang         3.  Yan       4.  Sungai Daun      5.  Singkir   |\n");
			printf("   ---------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==9){
			printf("\n\n******************* DISTRICT / DAERAH : LANGKAWI ********************\n");
			printf("   |  1.  Jeneri       2.  Sik         3.  Sok       4.  Teloi   |\n");
			printf("   ---------------------------------------------------------------\n");
		}
		
		else if (district==10){
			printf("\n\n****************************************** DISTRICT / DAERAH : PADANG TERAP ********************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Tualak                 4.  Belimbing Kanan             7.  Kurung Hitam                 10.  Pedu         |\n");
			printf("   |  2.  Pdg.Terap Kanan        5.  Belimbing Kiri              8.  Batang Tunggang Kanan        11.  Tekai Kanan  |\n");
			printf("   |  3.  Pdg.Terap Kiri         6.  Padang Temak                9.  Batang Tunggang Kiri         12.  Tekai Kiri   |\n");
			printf("   ------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==11){
			printf("\n\n******************* DISTRICT / DAERAH : POKOK SENA ********************\n");
	  		printf("   -----------------------------------------------------------------\n");
			printf("   |  1.  Gajah Mati         3.  Tualang         5.  Bukit Lada    |\n");
			printf("   |  2.  Jabi               4.  Lesong          6.  Derang        |\n");
			printf("   -----------------------------------------------------------------\n");
		}
		
		else if (district==12){
			printf("\n\n****************************** DISTRICT / DAERAH : BANDAR BAHARU *******************************\n");
	  		printf("   ------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bagan Samak         3.  Sg Kechil Llir         5.  Relau           7.  Sg Batu    |\n");
			printf("   |  2.  Permatang           4.  Serdang                6.  Selama                         |\n");
			printf("   ------------------------------------------------------------------------------------------\n");
		}
		
		printf("\nPlease choose your zone: ");
		scanf("%d", &zone);	
		
		while ((district == 1 && zone < 1) || (district == 1 && zone > 16)||(district == 2 && zone < 1) || (district == 2 && zone > 28)||
			   (district == 3 && zone < 1) || (district == 3 && zone > 15)||(district == 4 && zone < 1) || (district == 4 && zone > 21)||
			   (district == 5 && zone < 1) || (district == 5 && zone > 8)||(district == 6 && zone < 1) || (district == 6 && zone > 8)||
			   (district == 7 && zone < 1) || (district == 7 && zone > 6)||(district == 8 && zone < 1) || (district == 8 && zone > 5)||
			   (district == 9 && zone < 1) || (district == 9 && zone > 4)||(district == 10 && zone < 1) || (district == 10 && zone > 12)||
			   (district == 11 && zone < 1) || (district == 11 && zone > 6)||(district == 12 && zone < 1) || (district == 12 && zone > 7)){
      			printf("Error! Please re-enter your choice: \n");
     			scanf("%d", &zone);
      	}
		
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
	 	}
	 	
	 	else if (cases[a-1][b-1] > 0){
			printf("\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Kelantan() //Kelantan cases
{
	int a, b;
	int cases[10][15] =
	//  1   2	3	4	5	6	7	8	9  10	11	 12	  13   14	15
	{{ 34, 29, 16,  4, 33, 16, 72, 18, 15,  3,  52,  12,  28,  12,   8},	// Kota Bharu
	 {  5,  0,  5, 10, 11,  3, 15,  0,  0,  0,  -1,  -1,  -1,  -1,  -1},	// Pasir Mas 
	 { 21, 50,  2, 16,  3,  3,  9, -1, -1,  1,  -1,  -1,  -1,  -1,  -1},	// Tumpat
	 { 42,  8,  4,  2, 54, 19,  7,  1, -1, -1,  -1,  -1,  -1,  -1,  -1},	// Bachok 
	 {  3, 31, 55, -1, -1, -1, -1, -1, -1, -1,  -1,  -1,  -1,  -1,  -1},	// Tanah Merah 
	 { 10,  7, 10,  4, 15,  4,  5,  5, -1, -1,  -1,  -1,  -1,  -1,  -1},	// Pasir Puteh 
	 { 40, 39,  2, -1, -1, -1, -1, -1, -1, -1,  -1,  -1,  -1,  -1,  -1},	// Kuala Krai
	 { 34, 13, 15, 18,  4,  1, -1, -1, -1, -1,  -1,  -1,  -1,  -1,  -1},	// Machang
	 { 55, 69,  0, -1, -1, -1, -1, -1, -1, -1,  -1,  -1,  -1,  -1,  -1},	// Gua Musang 
	 { 17,  1,  0, -1, -1, -1, -1, -1, -1, -1,  -1,  -1,  -1,  -1,  -1}};	// Jeli 
	 
	 if(state==3){
		if (district==1){
			printf("\n\n********************************** DISTRICT / DAERAH : KOTA BHARU *************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kemumin             5.  Kbg.Kerian             9.  Badang              13.  Kadok        |\n");
			printf("   |  2.  Bndr.K.Bharu        6.  Ketereh               10.  Salor               14.  Pendek       |\n");
			printf("   |  3.  Kota                7.  Panji                 11.  Peringat            15.  Dewan Beta   |\n");
			printf("   |  4.  Sering              8.  Limbat                12.  Banggu                                |\n");
			printf("   -------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==2){
			printf("\n\n*********************************** DISTRICT / DAERAH : PASIR MAS **************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Gual Periok          4.  Kbg.Gadong              7.  Kangkong            10.  Alor Pasir  |\n");
			printf("   |  2.  Kuala Lemal          5.  Kubang Sepat            8.  Bunut Susu                           |\n");
			printf("   |  3.  R.Panjang            6. Pasir Mas                9.  Chetok                               |\n");
			printf("   --------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==3){
			printf("\n\n************************************ DISTRICT / DAERAH : TUMPAT **************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kebakat              3.  Sg.Pinang                5.  Terbak            7.  Jal Besar   |\n");
			printf("   |  2.  Wakaf Bharu          4.  Pgkln.Kubor              6.  Tumpat                            |\n");
			printf("   ------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==4){
			printf("\n\n************************************ DISTRICT / DAERAH : BACHOK **************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Tawang              3.  Perupok                5.  Melawi            7.  Tanjong Pauh   |\n");
			printf("   |  2.  Bekelam             4.  Mahligai               6.  Gunong            8.  Telong         |\n");
			printf("   ------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==5){
			printf("\n\n***************** DISTRICT / DAERAH : TANAH MERAH ******************\n");
	  		printf("   --------------------------------------------------------------\n");
			printf("   |  1.  Ulu Kusial          2.  Kusial           3.  Jedok    |\n");
			printf("   --------------------------------------------------------------\n");
		}
		
		else if (district==6){
			printf("\n\n********************************* DISTRICT / DAERAH : PASIR PUTEH ***********************************\n");
	  		printf("   -----------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Semerak            3.  Jeram               5.  Pdg.P.Amat             7.  Gong Batok   |\n");
			printf("   |  2.  Limbongan          4.  Bukit Jawa          6.  Bukit Abal             8.  Bukit Awang  |\n");
			printf("   -----------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==7){
			printf("\n\n************************** DISTRICT / DAERAH : KUALA KRAI **************************\n");
	  		printf("   ------------------------------------------------------------------------------\n");
			printf("   |  1.  Bt.Mengkebeng             2.  Olak Jeram               3.  Dabong     |\n");
			printf("   ------------------------------------------------------------------------------\n");
		}
		
		else if (district==8){
			printf("\n\n********************************** DISTRICT / DAERAH : MACHANG ************************************\n");
			printf("   ---------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Ulu Sat             3.  Labok             5.  Pgkl.Meleret          7.  Gong Batok   |\n");
			printf("   |  2.  P.Chondong          4.  Panyit            6.  Temangan              8.  Bukit Awang  |\n");
			printf("   ---------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==9){
			printf("\n\n****************** DISTRICT / DAERAH : GUA MUSANG *******************\n");
			printf("   ---------------------------------------------------------------\n");
			printf("   |  1.  Chiku              2.  Galas              3.  Bertam   |\n");
			printf("   ---------------------------------------------------------------\n");
		}
		
		else if (district==10){
			printf("\n\n*************************** DISTRICT / DAERAH : JELI *****************************\n");
	  		printf("   ----------------------------------------------------------------------------\n");
			printf("   |  1.  Jeli              2.  Batu Melintang              3.  Kuala Balah   |\n");
			printf("   ----------------------------------------------------------------------------\n");
		}
		
		printf("\nPlease choose your zone: ");
		scanf("%d", &zone);	
		
		while ((district == 1 && zone < 1) || (district == 1 && zone > 15)||(district == 2 && zone < 1) || (district == 2 && zone > 10)||
			   (district == 3 && zone < 1) || (district == 3 && zone > 7)||(district == 4 && zone < 1) || (district == 4 && zone > 8)||
			   (district == 5 && zone < 1) || (district == 5 && zone > 3)||(district == 6 && zone < 1) || (district == 6 && zone > 8)||
			   (district == 7 && zone < 1) || (district == 7 && zone > 3)||(district == 8 && zone < 1) || (district == 8 && zone > 8)||
			   (district == 9 && zone < 1) || (district == 9 && zone > 3)||(district == 10 && zone < 1) || (district == 10 && zone > 3)){
      			printf("Error! Please re-enter your choice: \n");
      			scanf("%d", &zone);
      	}
		
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
	 	}
	 	
	 	else if (cases[a-1][b-1] > 0){
			printf("\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Melaka() //Melaka cases
{
	int a, b;
	int cases[3][31] =
	// 1   2   3   4   5   6   7   8   9   10  11	12	 13	  14   15   16	 17	  18   19	20	 21	  22   23   24   25   26   27   28   29   30   31		
	{{ 5, 12, 10, 14, 22, 13, 19, 11, 16,  7,   0,  11,  43,  10,   1,  18,   7,   6,   1,   6,   3,   4,   8,   9,   4,   5,  11,  99,  0,   -1, -1},	// Melaka Tengah
	 { 1,  0,  0,  0,  3,  0,  7,  0,  0,  0,   0,   1,   1,   4,   0,   0,   0,   0,   0,   0,   2,   4,   5,   3,   1,   0,   4,   0,  25,   0,  0},	// Alor Gajah 
	 {10,  0,  1,  0,  0,  0,  0,  3,  0,  6,  10,   1,   1,   7,   2,   3,   1,  37,  12,   1,  18,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, -1}};	// Jasin
	
	if(state==4){
		if (district==1){
			printf("\n\n******************************************** DISTRICT / DAERAH : MELAKA TENGAH *****************************************************\n");
			printf("   ------------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Alai                 7.  Bertam              13.  Cheng               19.   Padang Temu         25.  Tangga Batu      |\n");
			printf("   |  2.  Ayer Molek           8.  Bukit Baru          14.  Duyong              20.   Paya Rumput         26.  Tanjong Kling    |\n");
			printf("   |  3.  Bachang              9.  Bukit Katil         15.  Kandang             21.   Peringgit           27.  Tanjong Minyak   |\n");
			printf("   |  4.  Balai Panjang       10.  Bukit Lintang       16.  Klebang Besar       22.   Pernu               28.  Telok Mas        |\n");
			printf("   |  5.  Bandar Melaka       11.  Bukit Piatu         17.  Klebang Kechil      23.   Semabok             29.  Ujong Pasir      |\n");
			printf("   |  6.  Batu Berendam       12.  Bukit Rambai        18.  Krubong             24.   Sungai Udang                              |\n");
			printf("   ------------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==2){
			printf("\n\n*************************************************** DISTRICT / DAERAH : ALOR GAJAH ************************************************************\n");
	  		printf("   -----------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Air Paabas           8.  Kemuning               15.  Melekek                  22.  Rembia                  29.  Taboh Naning     |\n");
			printf("   |  2.  Belimbing            9.  Kuala Linggi           16.  Padang Sebang            23.  Sungai Baru Ilir        30.  Tanjung Rimau    |\n");
			printf("   |  3.  Beringin            10.  Kuala Sungai Baru      17.  Parit Melana             24.  Sungai Baru Tengah      31.  Tebong           |\n");
			printf("   |  4.  Brisu               11.  Lendu                  18.  Pegoh                    25.  Sungai Baru Ulu                               |\n");
			printf("   |  5.  Durian Tunggal      12.  Machap                 19.  Pulau Sebang             26.  Sungai Buluh                                  |\n");
			printf("   |  6.  Gadek               13.  Masjid Tanah           20.  Ramuan China Besar       27.  Sungai Petai                                  |\n");
			printf("   |  7.  Kelemak             14.  Melaka Pindah          21.  Ramuan China Kecil       28.  Sungai Siput                                  |\n");
			printf("   -----------------------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==3){
			printf("\n\n******************************************* DISTRICT / DAERAH : JASIN *****************************************************\n");
			printf("   ---------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Ayer Panas             6.  Chin Chin          11.  Merlimau            16.  Sempang             21.  Umbai   |\n");
			printf("   |  2.  Bandar Jasin           7.  Chohong            12.  Nyalas              17.  Semujok                          |\n");
			printf("   |  3.  Batang Melaka          8.  Jasin              13.  Rim                 18.  Serkam                           |\n");
			printf("   |  4.  Bukit Senggeh          9.  Jus                14.  Sebatu              19.  Sungai Rambai                    |\n");
			printf("   |  5.  Chabau                10.  Kesang             15.  Selandar            20.  Tedong                           |\n");
			printf("   ---------------------------------------------------------------------------------------------------------------------\n");
		}
	
		printf("\nPlease choose your zone / Sila pilih zon anda: ");
		scanf("%d", &zone);	
		
		while ((district == 1 && zone < 1) || (district == 1 && zone > 29)||(district == 2 && zone < 1) || (district == 2 && zone > 31)||
			   (district == 3 && zone < 1) || (district == 3 && zone > 21)){
      			printf("Error! Please re-enter your choice: ");
      			scanf("%d", &zone);
    	}
		
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
		}
	 	
		else if (cases[a-1][b-1] > 0){
			printf("\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_NegeriSembilan() //Negeri Sembilan cases
{
	int a, b;
	int cases[7][17] =
	//   1    2    3	4	 5	  6	   7	8	 9	 10	  11   12	13	 14	  15   16	20
	{{ 273, 319,  42, 482, 170, 100, 152,   1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Seremban
	 {  24,  10,  19,   3,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Jempol 
	 { 461,  43,  21,   2,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   1,  -1,  -1,  -1,  -1},	// Port Dickson
	 {   7,  24,   0,   1,   0,   0,   0,   1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Tampin 
	 {   2,   0,   9,   4,  17,   8,   0,   0,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Kuala Pilah 
	 {  29,  23,   0,   3,   3,   1,   1,   0,   0,   2,   0,   0,   1,   2,   2,   0,   0},	// Rembau 
	 { 628,  18,   3,   1,   0,   4,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}};	// Jelebu
 
	if (state==5){
		if (district==1){
			printf("\n\n******************************* DISTRICT / DAERAH : SEREMBAN ***********************************\n");
	  		printf("   ------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Ampangan           3.  Seremban            5.  Rasah              7.  Lenggeng    |\n");
			printf("   |  2.  Labu               4.  Setul               6.  Rantau             8.  Pantai      |\n");
			printf("   ------------------------------------------------------------------------------------------\n");
		}
			
		else if (district==2){
			printf("\n\n**************************************** DISTRICT / DAERAH : JEMPOL *******************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Serting Ilir        2.  Jelai          3.  Rompin        4.  Kuala Jempol        5.  Serting Ulu  |\n");
			printf("   ---------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==3){
			printf("\n\n************************************* DISTRICT / DAERAH : PORT DICKSON ****************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Jimah        2.  Si Rusa          3.  Port Dickson        4.  Linggi        5.  Pasir Panjang  |\n");
			printf("   -------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (district==4){
			printf("\n\n****************************** DISTRICT / DAERAH : TAMPIN **********************************\n");
	  		printf("   --------------------------------------------------------------------------------------\n");
			printf("   |  1.  Tampin           3.  Keru               5.  Repah               7.  Tebong    |\n");
			printf("   |  2.  Gemas            4.  Gemenceh           6.  Air Kuning                        |\n");
			printf("   --------------------------------------------------------------------------------------\n");
		}	
			
		else if (district==5){
			printf("\n\n********************************** DISTRICT / DAERAH : KUALA PILAH *************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Terachi           4.  Ampang Tinggi           7.  Kepis                10.  Sri Menanti   |\n");
			printf("   |  2.  Ulu Muar          5.  Pilah                   8.  Langkap              11.  Ulu Jempol    |\n");
			printf("   |  3.  Johol             6.  Juasseh                 9.  Parit Tinggi                            |\n");
			printf("   --------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==6){
			printf("\n\n***************************************** DISTRICT / DAERAH : REMBAU *******************************************\n");
			printf("   ----------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Pedas                     6.  Chembong                11.  Bongek               16.  Miku         |\n");
			printf("   |  2.  Batu Hampar               7.  Gadong                  12.  Nerasau              17.  Legung Ulu   |\n");
			printf("   |  3.  Pilin                     8.  Chengkau                13.  Selemak                                |\n");
			printf("   |  4.  Kundur                    9.  Tanjung Keling          14.  Legung Ilir                            |\n");
			printf("   |  5.  Titian Bintangor         10.  Semerbok                15.  Sepri                                  |\n");
			printf("   ----------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==7){
			printf("\n\n*************************************** DISTRICT / DAERAH : JELEBU *******************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Gelami Lemi            3.  Pertang            5.  Peradong                 7.  Teriang Hilir    |\n");
			printf("   |  2.  Ulu Triang             4.  Kanaboi            6.  Kuala Kelawang           8.  Hulu Kelawang    |\n");
			printf("   --------------------------------------------------------------------------------------------------------\n");
		}
		
		printf("\nPlease choose your zone: ");
		scanf("%d", &zone);	
		
		while ((district == 1 && zone < 1) || (district == 1 && zone > 8)||(district == 2 && zone < 1) || (district == 2 && zone > 5)||
			   (district == 3 && zone < 1) || (district == 3 && zone > 5)||(district == 4 && zone < 1) || (district == 4 && zone > 7)||
			   (district == 5 && zone < 1) || (district == 5 && zone > 11)||(district == 6 && zone < 1) || (district == 6 && zone > 17)||
			   (district == 7 && zone < 1) || (district == 7 && zone > 8)){
      			printf("Error! Please re-enter your choice: ");
      			scanf("%d", &zone);
      	}
		
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
	 	}
	 	
	 	else if (cases[a-1][b-1] > 0){
			printf("\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Pahang() //Pahang cases
{
	int a, b;
	int cases[11][12] =
	// 1	2 	 3	  4	   5    6	 7	  8	   9   10	11	 12						
	{{15,   0,   4,  10,   0,   0,   5,  -1,  -1,  -1,  -1,  -1},	// Kuantan
	 {50,  69,  10,   0,   0,  15,  26,   0,  10,  10,  -1,  -1},	// Temerloh 
	 { 2,  10,  10,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Bentong
	 { 0,   1,  14,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Maran 
	 { 0,   0,   2,   0,   1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Rompin 
	 { 0,   2,   0,   3,   0,   0,   0,   0,   2,   0,   0,  -1},	// Pekan 
	 { 0,   0,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Bera
	 { 1,   3,   0,   2,   0,   0,   0,  -1,  -1,  -1,  -1,  -1},	// Raub
	 { 0,   2,   1,   0,   1,   0,   0,   0,   1,   0,  -1,  -1},	// Jerantut 
	 { 2,   1,   0,   0,   1,   0,   1,   0,   0,   0,   1,   0},   // Lipis
	 { 1,   0,   3,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}};	// Cameron Highlands
	  
	 if(state==6){
		if (district==1){
			printf("\n\n***************************************** DISTRICT / DAERAH : KUANTAN *******************************************\n");
	  		printf("   -----------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Beserah                  3.  Kuala Kuantan 2             5.  Penor               7.  Hulu Kuant    |\n");
			printf("   |  2.  Kuala Kuantan 1          4.  Sungai Karang               6.  Hulu Lepar                            |\n");
			printf("   -----------------------------------------------------------------------------------------------------------\n");
		}
				
		else if (district==2){
			printf("\n\n**************************************** DISTRICT / DAERAH : TEMERLOH ******************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Jenderak         3.  Kerdau              5.  Sanggang          7.  Mentakab           9.  Perak   |\n");
			printf("   |  2.  Semantan         4.  Lipat Kajang        6.  Songsang          8.  Bangau            10.  Lebak   |\n");
			printf("   ----------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==3){
			printf("\n\n************************ DISTRICT / DAERAH : BENTONG ***************************\n");
	  		printf("   --------------------------------------------------------------------------\n");
			printf("   |  1.  Bentong                2.  Sabai                 3.  Pelangai     |\n");
			printf("   --------------------------------------------------------------------------\n");
		}
	
		else if (district==4){
			printf("\n\n************************************ DISTRICT / DAERAH : MARAN **************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Chenor              2.  Kertau                3.  Luit             4.  Bukit Segumpal   |\n");
			printf("   ------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==5){
			printf("\n\n*************************************** DISTRICT / DAERAH : ROMPIN ***************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Endau           2.  Pontian            3.  Rompin            4. Tioman         5. Keratong  |\n");
			printf("   ----------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==6){
			printf("\n\n*********************************** DISTRICT / DAERAH : PEKAN ************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Pekan               4.  Kuala Pahang           7.  Ganchong            10.  Lepar   |\n");
			printf("   |  2.  Pahang Tua          5.  Langgar                8.  Temai               11.  Bebar   |\n");
			printf("   |  3.  Penyor              6.  Pulau Rusa             9.  Pulau Manis                      |\n");
			printf("   ------------------------------------------------------------------------------------------- \n");
		}
	
		else if (district==7){
			printf("\n\n*********************************** DISTRICT / DAERAH : BERA ***********************************\n");
	  		printf("   ------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bera 1             2.  Bera 2              3.  Triang 1            4. Triang 2    |\n");
			printf("   ------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==8){
			printf("\n\n********************************* DISTRICT / DAERAH : RAUB ***********************************\n");
			printf("   ----------------------------------------------------------------------------------------\n");
			printf("   |  1.  Tras             3.  Dong                5.  Semantan Ulu            7.  Sega   |\n");
			printf("   |  2.  Gali             4.  Ulu Dong            6.  Batu Talam                         |\n");
			printf("   ----------------------------------------------------------------------------------------\n");
		}

		else if (district==9){
			printf("\n\n************************************ DISTRICT / DAERAH : JERANTUT ************************************\n");
			printf("   ------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Tembeling               4.  Teh                7.  Kelola              10.  Ulu Cheka   |\n");
			printf("   |  2.  Kuala Tembeling         5.  Pedah              8.  Burau                                |\n");
			printf("   |  3.  Hulu Tembeling          6.  Pulau Tawar        9.  Tebing Tinggi                        |\n");
			printf("   ------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==10){
			printf("\n\n************************************* DISTRICT / DAERAH : LIPIS **************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kuala Lipis           4.  Kechau              7.  Gua              10.  Ulu Jerai       |\n");
			printf("   |  2.  Batu Yon 1            5.  Cheka 1             8.  Telang           11.  Budu            |\n");
			printf("   |  3.  Batu Yon 2            6.  Cheka 2             9.  Penjom           12.  Tanjung Besar   |\n");
			printf("   ------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==11){
			printf("\n\n********************** DISTRICT / DAERAH : CAMERON HIGHLANDS ************************\n");
	  		printf("   -------------------------------------------------------------------------------\n");
			printf("   |  1.  Tanah Rata                2.  Ringlet                 3.  Hulu Telom   |\n");
			printf("   -------------------------------------------------------------------------------\n");
		}
		
		printf("\nPlease choose your zone: ");
		scanf("%d", &zone);
		
		while ((district == 1 && zone < 1) || (district == 1 && zone > 7)||(district == 2 && zone < 1) || (district == 2 && zone > 10)||
		   	   (district == 3 && zone < 1) || (district == 3 && zone > 3)||(district == 4 && zone < 1) || (district == 4 && zone > 4)||
		   	   (district == 5 && zone < 1) || (district == 5 && zone > 5)||(district == 6 && zone < 1) || (district == 6 && zone > 11)||
		   	   (district == 7 && zone < 1) || (district == 7 && zone > 4)||(district == 8 && zone < 1) || (district == 8 && zone > 7)||
		   	   (district == 9 && zone < 1) || (district == 9 && zone > 10)||(district == 10 && zone < 1) || (district == 10 && zone > 12)||
		   	   (district == 11 && zone < 1) || (district == 11 && zone > 3)){
      			printf("Error! Please re-enter your choice: ");
      			scanf("%d", &zone);
    	}
    	
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
	 	}
	 	
	 	else if (cases[a-1][b-1] > 0){
			printf("\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Penang() //Penang cases
{
	int a, b;
	int cases[5][23] =
	//  1    2    3	   4	5	 6	  7    8	9	10	 11	  12   13	14	 15	  16   17   18   19   20   21   22   23
	{{130, 119,  19,  13,   0,   0,  16,   9,   2, 276,   0,   0,   0,   0,   3,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Timur Laut Pulau Pinang
	 {  9,   3,  31,   1,  12,   5,   2,  46,   1,   4,   1,   5,  23,  11,   8,  25,  43,  29,   3,   0,   0,  10,   0},	// Seberang Perai Tengah 
	 {  3,   3,   1,  35,   7,  46,   5,   0,   1,   3,  19,  13,   8,  36,  13,  17,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Seberang Perai Utara
	 {  4,   0,   3,   1,   2,  17,  12,   2,  27,   0,  49, 805,   2,   0,   4,   2,   0,   0,   1,   1,   0,   6,  -1},	// Barat Daya Pulau Pinang
	 {  7,   0,   0,   0,  13,  25,  11,   1,  14,   8,  26,   1,  43,  73,  25,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}};	// Seberang Perai Selatan 
	  
	 if(state==7){
		if (district==1){
			printf("\n\n************************************** DISTRICT / DAERAH : TIMUR LAUT PULAU PINANG ***************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bandar Georgetown        5.  Bandar Bukit Bendara           9.  Bandar Batu Feringghi       13.  Mukim 16   |\n");
			printf("   |  2.  Bandar Jelutong          6.  Bandar Tanjong Pinang         10.  Mukim 13                    14.  Mukim 17   |\n");
			printf("   |  3.  Bandar Gelugor           7.  Bandar Tanjong Tokong         11.  Mukim 14                    15.  Mukim 18   |\n");
			printf("   |  4.  Bandar Ayer Itam         8.  Bandar Tanjong Bungah         12.  Mukim 15                                    |\n");
			printf("   --------------------------------------------------------------------------------------------------------------------\n");
		}
				
		else if (district==2){
			printf("\n\n***************************************** DISTRICT / DAERAH : SEBERANG PERAI TENGAH *******************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bandar Prai                6.  Mukim 4            11.  Mukim 9            16.  Mukim 14          21.  Mukim 19   |\n");
			printf("   |  2.  Bandar Bukit Mertajam      7.  Mukim 5            12.  Mukim 10           17.  Mukim 15          22.  Mukim 20   |\n");
			printf("   |  3.  Mukim 1                    8.  Mukim 6            13.  Mukim 11           18.  Mukim 16          23.  Mukim 21   |\n");
			printf("   |  4.  Mukim 2                    9.  Mukim 7            14.  Mukim 12           19.  Mukim 17                          |\n");
			printf("   |  5.  Mukim 3                   10.  Mukim 8            15.  Mukim 13           20.  Mukim 18                          |\n");
			printf("   -------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==3){
			printf("\n\n*************************** DISTRICT / DAERAH : SEBERANG PERAI UTARA *****************************\n");
	  		printf("   --------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Mukim 1             5.  Mukim 5             9.  Mukim 9             13.  Mukim 13   |\n");
			printf("   |  2.  Mukim 2             6.  Mukim 6            10.  Mukim 10            14.  Mukim 14   |\n");
			printf("   |  3.  Mukim 3             7.  Mukim 7            11.  Mukim 11            15.  Mukim 15   |\n");
			printf("   |  4.  Mukim 4             8.  Mukim 8            12.  Mukim 12            16.  Mukim 16   |\n");
			printf("   --------------------------------------------------------------------------------------------\n");
		}
	
		else if (district==4){
			printf("\n\n*********************************** DISTRICT / DAERAH : BARAT DAYA PULAU PINANG ************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Mukim 1            6.  Mukim 6            11.  Mukim 11           16.  Mukim D          21.  Mukim I  |\n");
			printf("   |  2.  Mukim 2            7.  Mukim 7            12.  Mukim 12           17.  Mukim E          22.  Mukim J  |\n");
			printf("   |  3.  Mukim 3            8.  Mukim 8            13.  Mukim A            18.  Mukim F                        |\n");
			printf("   |  4.  Mukim 4            9.  Mukim 9            14.  Mukim B            19.  Mukim G                        |\n");
			printf("   |  5.  Mukim 5           10.  Mukim 10           15.  Mukim C            20.  Mukim H                        |\n");
			printf("   --------------------------------------------------------------------------------------------------------------\n");
		}		
		
		else if (district==5){
			printf("\n\n*************************** DISTRICT / DAERAH : SEBERANG PERAI SELATAN ***************************\n");
	  		printf("   --------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Mukim 1             5.  Mukim 5             9.  Mukim 9             13.  Mukim 13   |\n");
			printf("   |  2.  Mukim 2             6.  Mukim 6            10.  Mukim 10            14.  Mukim 14   |\n");
			printf("   |  3.  Mukim 3             7.  Mukim 7            11.  Mukim 11            15.  Mukim 15   |\n");
			printf("   |  4.  Mukim 4             8.  Mukim 8            12.  Mukim 12                            |\n");
			printf("   --------------------------------------------------------------------------------------------\n");
		}
		
	printf("\nPlease choose your zone: ");
	scanf("%d", &zone);	
		
	while ((district == 1 && zone < 1) || (district == 1 && zone > 15)||(district == 2 && zone < 1) || (district == 2 && zone > 23)||
		   (district == 3 && zone < 1) || (district == 3 && zone > 16)||(district == 4 && zone < 1) || (district == 4 && zone > 22)||
		   (district == 5 && zone < 1) || (district == 5 && zone > 15)){
      		printf("Error! Please re-enter your choice: n");
      		scanf("%d", &zone);
    }
		
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
	 	}
	 	
	 	else if (cases[a-1][b-1] > 0){
			printf("\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Perak() //Perak cases
{
	int a, b;
	int cases[12][11] =
	//  1   2   3	4	5	6	7	8	9	10	11					
	{{134, 44, 16, 19, 19,  1,  5,  9, -1, -1, -1},		// Kinta
	 {335,  3, 11, 11,  0,  1,  0,  6,  0, -1, -1},		// Larut, Matang Dan Selama 
	 { 38, 28,  2,  1,  0, -1, -1, -1, -1, -1, -1},		// Manjung
	 { 78, 13,  0,  1,  3, -1, -1, -1, -1, -1, -1},		// Hilir Perak 
	 { 23,  5,  0,  0,  8,  9,  6, 38, -1, -1, -1},		// Kerian 
	 { 36,  2,  2,  4, -1, -1, -1, -1, -1, -1, -1},		// Batang Padang 
	 { 11,  1,  9,  0,  0, 18,  7, 42,  0, -1, -1},		// Kuala Kangsar
	 {  8,  0,  7,  3,  0,  0,  0,  0,  0,  2,  0},		// Perak Tengah
	 {  0, 11,  1,  0,  0,  0,  7,  0,  3,  0, -1},		// Hulu Perak 
	 {  9, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1},     // Kampar
	 { 21,  0, 35, -1, -1, -1, -1, -1, -1, -1, -1},		// Muallim
	 {  9,  8,  7,  0, -1, -1, -1, -1, -1, -1, -1}};	// Bagan Datuk
	  
	 if(state==8){
		if (district==1){
			printf("\n\n********************************** DISTRICT / DAERAH : KINTA **************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Ipoh             3.  Lahat                5.  Sg. Terap             7.  Tronoh       |\n");
			printf("   |  2.  Chemor           4.  Tg Rambutan          6.  Sg. Raia              8.  Tg.Tualang   |\n");
			printf("   ---------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==2){
			printf("\n\n************************************* DISTRICT / DAERAH : LARUT, MATANG DAN SELAMA **************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Taiping         3.  Selama              5.  Hulu Selama          7.  Trong                  9.  Hulu Ijok  |\n");
			printf("   |  2.  Matang          4.  Batu Kurau          6.  Sg. Tinggi           8.  Bukit Gantang                         |\n");
			printf("   -------------------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==3){
			printf("\n\n******************************************* DISTRICT / DAERAH : MANJUNG **********************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Sitiawan           2.  Lumut            3.  Pengkalan Baharu             4. Lekir           5. Beruas   |\n");
			printf("   ----------------------------------------------------------------------------------------------------------------\n");
		}
	
		else if (district==4){
			printf("\n\n********************************************** DISTRICT / DAERAH : HILIR PERAK *************************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Durian Sebatang        2.  Changkat Jong          3.  Sg. Durian          4.  Labu Kubong          5.  Sg. Manik  |\n");
			printf("   --------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==5){
			printf("\n\n********************************************* DISTRICT / DAERAH : KERIAN ********************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bagan Serai                3.  Selinsing              5.  Beriah                     7.  Kuala Kurau   |\n");
			printf("   |  2.  Tanjung Piandang           4.  Bagan Tiang            6.  Gunung Semanggol           8.  Parit Buntar  |\n");
			printf("   ---------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==6){
			printf("\n\n*************************************** DISTRICT / DAERAH : BATANG PADANG ***************************************\n");
	  		printf("   -----------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Batang Padang              2.  Bidor                  3.  Chenderiang                 4.  Sungkai  |\n");
			printf("   ---------------------------------------------------------------------------------------------------------- \n");
		}
	
		else if (district==7){
			printf("\n\n*********************************************** DISTRICT / DAERAH : KUALA KANGSAR **********************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Sg. Siput          3.  Kota Lama Kiri         5.  Senggang         7.  Kampung Buala         9.  Kota Lama Kanan  |\n");
			printf("   |  2.  Lubuk Merbau       4.  Pulau Kemiri           6.  Sayong           8.  Chegar Galah                               |\n");
			printf("   --------------------------------------------------------------------------------------------------------------------------\n");
		}
	
		else if (district==8){
			printf("\n\n************************************ DISTRICT / DAERAH : PERAK TENGAH **************************************\n");
			printf("   ------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bota              4.  Bandar               7.  Kampong Gajah               10.  Pasir Salak   |\n");
			printf("   |  2.  Lambor            5.  Kota Setia           8.  Layang-Layang               11.  Pulau Tiga    |\n");
			printf("   |  3.  Belanja           6.  Jaya Baru            9.  Pasir Panjang Hulu                             |\n");
			printf("   ------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==9){
			printf("\n\n*************************************** DISTRICT / DAERAH : HULU PERAK **************************************\n");
			printf("   -----------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Durian Pipit          4.  Kenering            7.  Pengkalan Hulu             10.  Temelong   |\n");
			printf("   |  2.  Gerik                 5.  Temengor            8.  Belukar Semang                             |\n");
			printf("   |  3.  Kerunai               6.  Belum               9.  Lenggong                                   |\n");
			printf("   -----------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==10){
			printf("\n\n************* DISTRICT / DAERAH : KAMPAR *************\n");
	  		printf("   ------------------------------------------------\n");
			printf("   |  1.  Kampar                   2.  Teja       |\n");
			printf("   ------------------------------------------------\n");
		}
	
		else if (district==11){
			printf("\n\n********************************* DISTRICT / DAERAH : MUALLIM **********************************\n");
	  		printf("   ------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Hulu Bernam Timur                2.  Hulu Bernam Barat                 3.  Slim   |\n");
			printf("   ------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==12){
			printf("\n\n***************************************** DISTRICT / DAERAH : BAGAN DATUK ****************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Hutan Melintang             2.  Bagan Datuk               3.  Rungkup               4.  Teluk Baru  |\n");
			printf("   ----------------------------------------------------------------------------------------------------------- \n");
		}
	
		printf("\nPlease choose your zone: ");
		scanf("%d", &zone);	
		
		while ((district == 1 && zone < 1) || (district == 1 && zone > 8)||(district == 2 && zone < 1) || (district == 2 && zone > 9)||
		  	   (district == 3 && zone < 1) || (district == 3 && zone > 5)||(district == 4 && zone < 1) || (district == 4 && zone > 5)||
		  	   (district == 5 && zone < 1) ||(district == 5 && zone > 8)||(district == 6 && zone < 1) || (district == 6 && zone > 4)||
		   	   (district == 7 && zone < 1) || (district == 7 && zone > 9)||(district == 8 && zone < 1) || (district == 8 && zone > 11)||
		   	   (district == 9 && zone < 1) || (district == 9 && zone > 10)||(district == 10 && zone < 1) || (district == 10 && zone > 2)||
		   	   (district == 11 && zone < 1) || (district == 11 && zone > 3)||(district == 12 && zone < 1) || (district == 12 && zone > 4)){
      			printf("Error! Please re-enter your choice: ");
      			scanf("%d", &zone);
    	}
		
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
	 	}
	 	
	 	else if (cases[a-1][b-1] > 0){
			printf("\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Perlis() //Perlis cases
{
	int b;
	int cases[22] =
	// 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22													
	{  0, 1, 2, 1, 0, 1, 3, 5, 3,  0,  0,  0, 14,  0,  0,  8,  0,  3,  0,  2,  5,  4};		
	
	if(state==9){
		printf("\n\n************************************************** STATE / NEGERI : PERLIS ****************************************************\n");
		printf("   -------------------------------------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Abu              6.  Kayang                11.  Ngulang               16.  Sanglang          21.  Utan Aji       |\n");
		printf("   |  2.  Arau             7.  Kechor                12.  Oran                  17.  Sena              22.  Wang Bintong   |\n");
		printf("   |  3.  Beseri           8.  Kuala Perlis          13.  Padang Pauh           18.  Seriab                                |\n");
		printf("   |  4.  Chuping          9.  Kurung Anai           14.  Padang Siding         19.  Sungai Adam                           |\n");
		printf("   |  5.  Jejawi          10.  Kurung Batang         15.  Paya                  20.  Titi Tinggi                           |\n");
		printf("   -------------------------------------------------------------------------------------------------------------------------\n");
	
	printf("\nPlease choose your zone: ");
	scanf("%d", &zone);	
	
  	while ((state == 9 && zone < 1 || state == 9 && zone > 22)){
      		printf("Error! Please re-enter your choice: ");
      		scanf("%d", &zone);
    }
	
	b = zone;
		
	if (cases[b-1] >= 41){
	 	printf("\n\n** Current Location Risk: RED ZONE !!! **");
	 	printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[b-1]);
	 	printf("\n\n--------------------------------------------------------------------------------------------------------");
	 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 	printf("\n--------------------------------------------------------------------------------------------------------\n");
	}
	 	 	
	else if (cases[b-1] > 0){
		printf("\n\n** Current Location Risk: YELLOW ZONE !!! **");
	 	printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[b-1]);
	 	printf("\n--------------------------------------------------------------------------------------------------------");
	 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
		printf("\n--------------------------------------------------------------------------------------------------------\n");	
	}
		
	else if (cases[b-1] == 0){
		printf("\n\n** Current Location Risk: GREEN ZONE  **");
		printf("\n--------------------------------------------------------------------------------------------------------");
	 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
		printf("\n--------------------------------------------------------------------------------------------------------\n");	
	}
	}
}

void case_Sabah() //Sabah cases
{
	int a, b;
	int cases[25][20] =
	// 1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20													
	{{15,  0, 10,  3, 10,  0, 15,  0,  0,  0,  0,  3,  3,  0,  0,  0, -1, -1, -1, -1},	// Kota Kinabalu
	 { 5,  0,  0,  4,  3,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Tawau 
	 { 3,  0,  0,  1,  3,  0,  5,  0,  0,  1,  0,  3,  3,  0,  0, -1, -1, -1, -1, -1},	// Sandakan 
	 { 1,  0,  2,  1,  2,  1,  5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Lahad Datu 
	 { 0,  0,  0,  3,  0,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Keningau 
	 { 0,  0,  2,  1,  2,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Kinabatangan  
	 { 0,  0,  1,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Semporna
	 { 1,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  3,  3,  0,  0,  0,  1,  0,  0, -1},	// Papar
	 { 0,  0,  0,  3,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Penampang 
	 { 0,  0,  0,  1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Beluran
	 { 1,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  1, -1, -1, -1},	// Tuaran
	 { 1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1},	// Ranau
	 { 0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  3,  3,  0,  0,  0,  1,  0,  0,  1},	// Kota Belud
	 { 0,  0,  0,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Kudat
	 { 1,  0,  0,  0,  2,  0,  0,  0,  0,  1,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1},	// Kota Marudu
	 { 0,  0,  1,  0,  1,  0,  0,  0,  0,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Beaufort
	 { 1,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Kunak
	 { 0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Tenom
	 { 0,  1,  1,  0,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Putatan
	 { 0,  0,  1,  0,  1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Pitas
	 { 0,  1,  1,  1,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Tambunan
	 { 1,  0,  1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Tongod
	 { 0,  0,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Sipitang
	 { 1,  0,  1,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},	// Nabawan
	 { 1,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};	// Kuala Penyu 

	if(state==10){
		if (district==1){
			printf("\n\n********************************** DISTRICT / DAERAH : KOTA KINABALU ************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Tanjung Aru           5.  Luyang B              9.  Pulau Gaya               13.  Tembok   |\n");
			printf("   |  2.  Sembulan              6.  Luyang C             10.  Laut                     14.  Kionsom  |\n");
			printf("   |  3.  Kampung Air           7.  Luyang D             11.  Pekan dan Taman          15.  Darat    |\n");
			printf("   |  4.  Luyang A              8.  Likas                12.  Pantai                   16.  Petagas  |\n");
			printf("   ---------------------------------------------------------------------------------------------------\n");
		}
				
		else if (district==2){
			printf("\n\n************************************************* DISTRICT / DAERAH : TAWAU *************************************************\n");
	  		printf("   -----------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kalabakan       2.  Sri Tanjung        3.  Wallace Bay        4.  Brumas        5.  Merotai        6.  Balung  |\n");
			printf("   -----------------------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==3){
			printf("\n\n*********************************** DISTRICT / DAERAH : SANDAKAN *************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Sentosa           5.  Sibuga                9.  Suan Lamba           13.  Jalan Lela    |\n");
			printf("   |  2.  P. Elopura        6.  Beatrice             10.  Ulu Dusun            14.  Sungai Sapi   |\n");
			printf("   |  3.  Batu Sapi         7.  Berhala              11.  Trig Hill            15.  Mamiang       |\n");
			printf("   |  4.  Cecily            8.  Karamunting          12.  Segaliud                                |\n");
			printf("   ------------------------------------------------------------------------------------------------\n");
		}
			
		else if (district==4){
			printf("\n\n****************************** DISTRICT / DAERAH : LAHAD DATU ******************************\n");
	  		printf("   --------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bandar           3.  Silabukan             5.  Tambisan            7.  Felda  |\n");
			printf("   |  2.  Segama           4.  Silam                 6.  Tungku                         |\n");
			printf("   --------------------------------------------------------------------------------------\n");
		}
	
		else if (district==5){
			printf("\n\n*********************************************** DISTRICT / DAERAH : KENINGAU *************************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Tuarid Taud         3.  Bingkor              5.  Apin-Apin           7.  Lingkudau            9.  Patikang Ulu  |\n");
			printf("   |  2.  Luagan              4.  Bunga Raya           6.  Senagang            8.  Bulu Silou                             |\n");
			printf("   ------------------------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==6){
			printf("\n\n************************************************ DISTRICT / DAERAH : KINABATANGAN **************************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Buang Sayang         2.  Batu Puteh           3.  Jeroco           4.  Kuamut         5.  Paris            6.  Sukau  |\n");
			printf("   ------------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==7){
			printf("\n\n********************************************** DISTRICT / DAERAH : SEMPORNA *************************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Tampi-Tampi          2.  Bugaya           3.  Pegagau            4.  Bum-Bum Selatan         5.  Bum-Bum Utara  |\n");
			printf("   ------------------------------------------------------------------------------------------------------------------------\n");
		}
	
		else if (district==8){
			printf("\n\n********************************************** DISTRICT / DAERAH : PAPAR ***********************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Gana/Kaiduan             6.  Kimanis/Mandahan          11.  Benon                  16.  Kinaruti          |\n");
			printf("   |  2.  Batu 6                   7.  Gadong                    12.  Buang Sayang           17.  Kuala Pus         |\n");
			printf("   |  3.  Biau/Dambai              8.  Kimanis Estet             13.  Pekan                  18.  Bongawan/Estete   |\n");
			printf("   |  4.  Bongawan                 9.  Limbahau                  14.  Kabang                 19.  Daingin Kimanis   |\n");
			printf("   |  5.  Pengalat Kawang         10.  Kuala                     15.  Laba/Kinarut                                  |\n");
			printf("   ------------------------------------------------------------------------------------------------------------------\n");
		}
			
		else if (district==9){
			printf("\n\n************************************ DISTRICT / DAERAH : PENAMPANG ***************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Moyog                3.  Donggongon            5.  Kobusak              7.  Penampang Baru  |\n");
			printf("   |  2.  Inobong              4.  Sugud                 6.  Kepayan              8.  Bahang          |\n");
			printf("   ----------------------------------------------------------------------------------------------------\n");
		}

		else if (district==10){
			printf("\n\n******************************************* DISTRICT / DAERAH : BELURAN *********************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Klagan             2.  Kolapis              3.  Nangoh             4.  Sapi              5.  Tetabuan  |\n");
			printf("   ---------------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==11){
			printf("\n\n*************************************************** DISTRICT / DAERAH : TUARAN ******************************************************\n");
			printf("   -------------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Berungis           5.  Indai             9.  Pantai            13.  Topokon                     17.  Gayaratau/Rungus  |\n");
			printf("   |  2.  Mangkabung         6.  Ulu              10.  Nabulu            14.  Sawah                                              |\n");
			printf("   |  3.  Tambalang          7.  Tengah           11.  Pekan             15.  Marabahai/Tuaran Bandar                            |\n");
			printf("   |  4.  Serusop            8.  Lembah           12.  Tengilan          16.  Tamparuli                                          |\n");
			printf("   -------------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==12){
			printf("\n\n**************************************************** DISTRICT / DAERAH : RANAU *******************************************************\n");
			printf("   --------------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kundasang         4.  Karanan/Tagudon          7.  Paginatan            10.  Tambiou/Mohimboyon            13.  Liwagu  |\n");
			printf("   |  2.  Kaingaran         5.  Lohan/Bongkud            8.  Perancangan          11.  Tanah Rata/Kintuntul                       |\n");
			printf("   |  3.  Malinsau          6.  Nalapak                  9.  Randagong            12.  Timbua                                     |\n");
			printf("   --------------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==13){
			printf("\n\n*********************************************** DISTRICT / DAERAH : KOTA BELUD **************************************************\n");
			printf("   ---------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Ambong                   5.  Wariou              9.  Kelawat             13.  Mangkulat          17.  Sembirai     |\n");
			printf("   |  2.  Bandar Kota Belud        6.  Kadamaian          10.  Kulambai            14.  Pirasan            18.  Taginambur   |\n");
			printf("   |  3.  Dudar                    7.  Kebayau            11.  Kinasaraban         15.  Rampayan           19.  Tan Gusi     |\n");
			printf("   |  4.  Kaguraan                 8.  Kedatuan           12.  Lasau               16.  Rosok              20.  Tampasuk     |\n");
			printf("   ---------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==14){
			printf("\n\n************************************** DISTRICT / DAERAH : KUDAT ***************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Banggi            2.  Timbang Dayang              3.  Dialog              4.  Tiga Papan    |\n");
			printf("   ----------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==15){
			printf("\n\n********************************************* DISTRICT / DAERAH : KOTA MARUDU ************************************************\n");
			printf("   ------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Batula         4.  Luba Pelumpung          7.  Ongkilan            10.  Taritipan            13.  Ulu Bengkoka  |\n");
			printf("   |  2.  Bongon         5.  Marak Parak             8.  Tagaroh             11.  Tingkalanon                             |\n");
			printf("   |  3.  Gana           6.  Mengaris                9.  Talantang           12.  Simpangan                               |\n");
			printf("   ------------------------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==16){
			printf("\n\n******************************************** DISTRICT / DAERAH : BEAUFORT ***********************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kota Klias        3.  Montenior          5.  Bandar Beaufort         7.  Mukim II            9.  Mukim IV  |\n");
			printf("   |  2.  Limbawang         4.  Klias Baru         6.  Mukim I                 8.  Mukim III          10.  Mukim V   |\n");
			printf("   -------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==17){
			printf("\n\n*************************** DISTRICT / DAERAH : KUNAK ****************************\n");
	  		printf("   ----------------------------------------------------------------------------\n");
			printf("   |  1.  Madai                    2.  Pekan                      3.  Pangi   |\n");
			printf("   ----------------------------------------------------------------------------\n");
		}

		else if (district==18){
			printf("\n\n************** DISTRICT / DAERAH : TENOM ***************\n");
	  		printf("   --------------------------------------------------\n");
			printf("   |  1.  Melalap                   2.  Pekan       |\n");
			printf("   --------------------------------------------------\n");
		}
		
		else if (district==19){
			printf("\n\n***************************************** DISTRICT / DAERAH : PUTATAN *****************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Buit          2.  Lok Kawi          3.  Pasir Putih           4.  Petagas           5.  Putatan  |\n");
			printf("   ---------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==20){
			printf("\n\n************************************************** DISTRICT / DAERAH : PITAS ***************************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kalumpang       2.  Pinggan-pinggan       3.  Mapan-Mapan         4.  Pantai        5.  Dandun        6.  Telaga  |\n");
			printf("   --------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==21){
			printf("\n\n********************************** DISTRICT / DAERAH : TAMBUNAN ***************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kirokot            3.  Sunsuron              5.  Luntuhan               7.  Monsurulung  |\n");
			printf("   |  2.  Patau              4.  Toboh                 6.  Nambayan                                |\n");
			printf("   -------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==22){
			printf("\n\n********************************** DISTRICT / DAERAH : TONGOD **********************************\n");
	  		printf("   ------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Entilibon          2.  Kuala Tongod           3.  Kuamut            4.  Penangah  |\n");
			printf("   ------------------------------------------------------------------------------------------\n");
		}

		else if (district==23){
			printf("\n\n*********************** DISTRICT / DAERAH : SIPITANG *************************\n");
	  		printf("   ------------------------------------------------------------------------\n");
			printf("   |  1.  Sindumin              2.  Masapol               3.  Melamam     |\n");
			printf("   ------------------------------------------------------------------------\n");
		}
		
		else if (district==24){
			printf("\n\n******************************** DISTRICT / DAERAH : NABAWAN **************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Nabawan              3.  Pamuntarian             5.  Salong            7.  Tatalaan  |\n");
			printf("   |  2.  Pagalungan           4.  Pensiangan              6.  Sepulut                         |\n");
			printf("   ---------------------------------------------------------------------------------------------\n");
		}	
 
		else if (district==25){
			printf("\n\n******************************** DISTRICT / DAERAH : KUALA PENYU *********************************\n");
	  		printf("   --------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bundu              2.  Kerukan              3.  Mantabawan           4.  Sitompok   |\n");
			printf("   --------------------------------------------------------------------------------------------\n");
		}
		
	printf("\nPlease choose your zone: ");
	scanf("%d", &zone);	
	
	while ((district == 1 && zone < 1) || (district == 1 && zone > 16)||(district == 2 && zone < 1) || (district == 2 && zone > 6)||
		   (district == 3 && zone < 1) || (district == 3 && zone > 15)||(district == 4 && zone < 1) || (district == 4 && zone > 7)||
		   (district == 5 && zone < 1) || (district == 5 && zone > 9)||(district == 6 && zone < 1) || (district == 6 && zone > 6)||
		   (district == 7 && zone < 1) || (district == 7 && zone > 5)||(district == 8 && zone < 1) || (district == 8 && zone > 19)||
		   (district == 9 && zone < 1) || (district == 9 && zone > 8)||(district == 10 && zone < 1) || (district == 10 && zone > 5)||
		   (district == 11 && zone < 1) || (district == 11 && zone > 17)||(district == 12 && zone < 1) || (district == 12 && zone > 13)||
		   (district == 13 && zone < 1) || (district == 13 && zone > 20)||(district == 14 && zone < 1) || (district == 14 && zone > 4)||
		   (district == 15 && zone < 1) || (district == 15 && zone > 13)||(district == 16 && zone < 1) || (district == 16 && zone > 10)||
		   (district == 17 && zone < 1) || (district == 17 && zone > 3)||(district == 18 && zone < 1) || (district == 18 && zone > 2)||
		   (district == 19 && zone < 1) || (district == 19 && zone > 5)||(district == 20 && zone < 1) || (district == 20 && zone > 6)||
		   (district == 21 && zone < 1) || (district == 21 && zone > 7)||(district == 22 && zone < 1) || (district == 22 && zone > 4)||
		   (district == 23 && zone < 1) || (district == 23 && zone > 3)||(district == 24 && zone < 1) || (district == 24 && zone > 7)||
		   (district == 25 && zone < 1) || (district == 25 && zone > 4)){
      		printf("Error! Please re-enter your choice: ");
      		scanf("%d", &zone);
    } 

		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
		 	printf("\n\n** Current Location Risk: RED ZONE !!! **");
		 	printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
		 	printf("\n\n--------------------------------------------------------------------------------------------------------");
		 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
		 	printf("\n--------------------------------------------------------------------------------------------------------\n");
		}
	 	 	
		else if (cases[a-1][b-1] > 0){
			printf("\n\n** Current Location Risk: YELLOW ZONE !!! **");
		 	printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
		 	printf("\n--------------------------------------------------------------------------------------------------------");
		 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Sarawak() //Sarawak cases
{
	int a, b;
	int cases[12][11] =
	//  1   2   3	4	5	6	7	8	9	10	11						
	{{ 63,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1},		// Kuching
	 {145,  0,  0,  0,  0,  0, 15,  0,  0,  0,  0},		// Miri 
	 {517,  7,  4, -1, -1, -1, -1, -1, -1, -1, -1},		// Sibu 
	 {  4,  0, 24, -1, -1, -1, -1, -1, -1, -1, -1},		// Bintulu 
	 {  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1},		// Serian 
	 {  2,  2,  1, -1, -1, -1, -1, -1, -1, -1, -1},		// Samarahan  
	 {  3,  0,  0,  2,  0, -1, -1, -1, -1, -1, -1},		// Sri Aman
	 {  0,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1},		// Betong
	 {  2,  2,  2,  0, -1, -1, -1, -1, -1, -1, -1},		// Sarikei
	 {  1,  0,  0,  0,  0,  1, -1, -1, -1, -1, -1},		// Kapit
	 {  1,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1},		// Limbang
	 {  0,  0, 17,  0,  0,  0,  0,  0, -1, -1, -1}};	// Mukah
 
	if(state==11){
		if (district==1){
			printf("\n\n*************************************** DISTRICT / DAERAH : KUCHING *****************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kuching            2.  Padawan            3.  Bau             4.  Lundu           5.  Sematan  |\n");
			printf("   -------------------------------------------------------------------------------------------------------\n");
		}
	
		else if (district==2){
			printf("\n\n************************************* DISTRICT / DAERAH : MIRI ***************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Miri               4.  Mulu                 7.  Beluru                10.  Long Lama    |\n");
			printf("   |  2.  Bario              5.  Subis                8.  Tinjar                11.  Long Bedian  |\n");
			printf("   |  3.  Marudi             6.  Niah Suai            9.  Telang Usan                             |\n");
			printf("   ------------------------------------------------------------------------------------------------\n");
		}

		else if (district==3){
			printf("\n\n******************** DISTRICT / DAERAH : SIBU ***********************\n");
	  		printf("   ---------------------------------------------------------------\n");
			printf("   |  1.  Sibu              2.  Kanowit            3.  Selangau  |\n");
			printf("   ---------------------------------------------------------------\n");
		}

		else if (district==4){
			printf("\n\n********************* DISTRICT / DAERAH : BINTULU ********************\n");
	  		printf("   ----------------------------------------------------------------\n");
			printf("   |  1.  Bintulu           2.  Tatau               3.  Sebauh    |\n");
			printf("   ----------------------------------------------------------------\n");
		}
		
		else if (district==5){
			printf("\n\n******************** DISTRICT / DAERAH : SERIAN ***********************\n");
	  		printf("   -----------------------------------------------------------------\n");
			printf("   |  1.  Serian            2.  Siburan            3.  Tebedu      |\n");
			printf("   -----------------------------------------------------------------\n");
		}
		
		else if (district==6){
			printf("\n\n************************************* DISTRICT / DAERAH : SAMARAHAN ****************************************\n");
	  		printf("   ------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kota Samarahan              2.  Asajaya               3.  Simunjan               4.  Sebuyau  |\n");
			printf("   ------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==7){
			printf("\n\n************************************** DISTRICT / DAERAH : SRI AMAN *****************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Sri Aman          2.  Lingga         3.  Pantu          4.  Lubok Antu          5.  Engkilili  |\n");
			printf("   -------------------------------------------------------------------------------------------------------\n");
		}
	
		else if (district==8){
			printf("\n\n**************************************** DISTRICT / DAERAH : BETONG *****************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Betong           3.  Debak             5.  Nanga Budu          7.  Maludam          9.  Roban  |\n");
			printf("   |  2.  Spaoh            4.  Saratok           6.  Pusa                8.  Kabong                      |\n");
			printf("   -------------------------------------------------------------------------------------------------------\n");
		}
			
		else if (district==9){
			printf("\n\n***************************** DISTRICT / DAERAH : SARIKEI ******************************\n");
	  		printf("   ----------------------------------------------------------------------------------\n");
			printf("   |  1.  Sarikei           2.  Meradong           3.  Julau             4.  Pakan  |\n");
			printf("   ----------------------------------------------------------------------------------\n");
		}
	
		else if (district==10){
			printf("\n\n*********************************************** DISTRICT / DAERAH : KAPIT *************************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kapit        2.  Nanga Merit        3.  Belaga        4.  Sg Asap         5.  Song          6.  Bukit Mabong |\n");
			printf("   ---------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==11){
			printf("\n\n************************************* DISTRICT / DAERAH : LIMBANG ***************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Limbang        2.  Nanga Medamit         3.  Lawas          4.  Sundar         5.  Trusan  |\n");
			printf("   ---------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==12){
			printf("\n\n********************************** DISTRICT / DAERAH : MUKAH *************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Mukah                3.  Dalat             5.  Matu              7.  Daro           |\n");
			printf("   |  2.  Balingian            4.  Oya               6.  Igan              8.  Tanjung Manis  |\n");
			printf("   --------------------------------------------------------------------------------------------\n");
		}
	
	printf("\nPlease choose your zone: ");
	scanf("%d", &zone);	
	
	while ((district == 1 && zone < 1) || (district == 1 && zone > 5)||(district == 2 && zone < 1) || (district == 2 && zone > 11)||
		   (district == 3 && zone < 1) || (district == 3 && zone > 3)||(district == 4 && zone < 1) || (district == 4 && zone > 3)||
		   (district == 5 && zone < 1) || (district == 5 && zone > 3)||(district == 6 && zone < 1) || (district == 6 && zone > 4)||
		   (district == 7 && zone < 1) || (district == 7 && zone > 5)||(district == 8 && zone < 1) || (district == 8 && zone > 9)||
		   (district == 9 && zone < 1) || (district == 9 && zone > 4)||(district == 10 && zone < 1) || (district == 10 && zone > 6)||
		   (district == 11 && zone < 1) || (district == 11 && zone > 5)||(district == 12 && zone < 1) || (district == 12 && zone > 8)){
      		printf("Error! Please re-enter your choice: ");
      		scanf("%d", &zone);
    }
		
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n\n** Current Location Risk: RED ZONE !!! **");
		 	printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
		 	printf("\n\n--------------------------------------------------------------------------------------------------------");
		 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
		 	printf("\n--------------------------------------------------------------------------------------------------------\n");
		}
	 	 	
		else if (cases[a-1][b-1] > 0){
			printf("\n\n** Current Location Risk: YELLOW ZONE !!! **");
		 	printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
		 	printf("\n--------------------------------------------------------------------------------------------------------");
		 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
		 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Selangor() //Selangor cases
{
	int a, b;
	int cases[9][13] =
	//  1     2		3	  4		5	  6	   7	8    9   10   11   12   13						
	{{ 149,  949,  366,  280,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Petaling
	 { 525,   39,  375,   67, 1016, 302,   0,  -1,  -1,  -1,  -1,  -1,  -1},	// Hulu Langat 
	 {2981, 1929,   -1,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Klang 
	 { 470,  132,   42,  344,   76,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Gombak 
	 { 271,   75,  237,   10,   17,  22,  32,   1,  -1,  -1,  -1,  -1,  -1},	// Kuala Langat 
	 { 829,  173,   78,   -1,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},	// Sepang  
	 {  68,  144,   59,   33,    1,  24,  24,   0,   6,  -1,  -1,  -1,  -1},	// Kuala Selangor
	 {  23,    7,    9,   11,   57,   0,  10,  24,   0,   3,   0,   0,   0},	// Hulu Selangor
	 {  10,   17,   10,    0,   12,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}};	// Sabak Bernam
	 	
	if(state==12){
		if (district==1){
			printf("\n\n************************************ DISTRICT / DAERAH : PETALING **************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bukit Raja            2.  Damansara               3.  Petaling             4.  Sg. Buloh  |\n");
			printf("   --------------------------------------------------------------------------------------------------\n");
		}
				
		else if (district==2){
			printf("\n\n*********************************** DISTRICT / DAERAH : HULU LANGAT ************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Ampang              3.  Cheras                 5.  Kajang               7.  H. Semenyih   |\n");
			printf("   |  2.  Beranang            4.  Hulu Langat            6.  Semenyih                               |\n");
			printf("   --------------------------------------------------------------------------------------------------\n");
		}

		else if (district==3){
			printf("\n\n*************** DISTRICT / DAERAH : KLANG *****************\n");
	  		printf("   -----------------------------------------------------\n");
			printf("   |  1.  Kapar                     2.  Klang          |\n");
			printf("   -----------------------------------------------------\n");
		}
		
		else if (district==4){
			printf("\n\n*************************************** DISTRICT / DAERAH : GOMBAK **************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Batu         2.  Hulu Kelang           3.  Kuang          4.  Rawang          5.  Setapak  |\n");
			printf("   ---------------------------------------------------------------------------------------------------\n");
		}

		else if (district==5){
			printf("\n\n*********************************** DISTRICT / DAERAH : KUALA LANGAT ************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Tanjung 12 (1)           3.  Tlk.Pg.Garang            5.  Bandar            7.  Morib      |\n");
			printf("   |  2.  Tanjung 12 (2)           4.  Batu                     6.  Jugra             8.  Kelanang   |\n");
			printf("   ---------------------------------------------------------------------------------------------------\n");
		}

		else if (district==6){
			printf("\n\n********************* DISTRICT / DAERAH : SEPANG **********************\n");
	  		printf("   -----------------------------------------------------------------\n");
			printf("   |  1.  Dengkil              2.  Labu              3.  Sepang    |\n");
			printf("   -----------------------------------------------------------------\n");
		}

		else if (district==7){
			printf("\n\n******************************************* DISTRICT / DAERAH : KUALA SELANGOR **********************************************\n");
	  		printf("   -----------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.   Bestari Jaya        3.  Jeram                  5.  Pasangan          7.  Api-Api            9.  Hujung Pmtg.  |\n");
			printf("   |  2.   Ijok                4.  Kuala Selangor         6.  Tg.Karang         8.  Hulu Tinggi                          |\n");
			printf("   -----------------------------------------------------------------------------------------------------------------------\n");
		}
	
		else if (district==8){
			printf("\n\n*********************************** DISTRICT / DAERAH : HULU SELANGOR ************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Ampang Pecah            5.  Serendah               9.  Pertak             13.  K.Kalumpang  |\n");
			printf("   |  2.  Batang Kali             6.  Buluh Telur           10.  Rasa                                 |\n");
			printf("   |  3.  Hulu Bernam             7.  Hulu Yam              11.  Sg.Gumut                             |\n");
			printf("   |  4.  Kalumpang               8.  Kerling               12.  Sg.Tinggi                            |\n");
			printf("   ----------------------------------------------------------------------------------------------------\n");
		}
	
		else if (district==9){
			printf("\n\n******************************************** DISTRICT / DAERAH : SABAK BERNAM ********************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bagan N.Omar         2.  Pancang Bedena         3.  Sabak          4.  Sg. Panjang       5.  Pasir Panjang  |\n");
			printf("   --------------------------------------------------------------------------------------------------------------------\n");
		}
	
	printf("\nPlease choose your zone: ");
	scanf("%d", &zone);	
	
	while ((district == 1 && zone < 1) || (district == 1 && zone > 4)||(district == 2 && zone < 1) || (district == 2 && zone > 7)||
		   (district == 3 && zone < 1) || (district == 3 && zone > 2)||(district == 4 && zone < 1) || (district == 4 && zone > 5)||
		   (district == 5 && zone < 1) || (district == 5 && zone > 8)||(district == 6 && zone < 1) || (district == 6 && zone > 3)||
		   (district == 7 && zone < 1) || (district == 7 && zone > 9)||(district == 8 && zone < 1) || (district == 8 && zone > 13)||
		   (district == 9 && zone < 1) || (district == 9 && zone > 5)){
      		printf("Error! Please re-enter your choice: ");
      		scanf("%d", &zone);
    }
	
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
		 	printf("\n\n** Current Location Risk: RED ZONE !!! **");
		 	printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
		 	printf("\n\n--------------------------------------------------------------------------------------------------------");
		 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
		 	printf("\n--------------------------------------------------------------------------------------------------------\n");
		}
	 	 	
		else if (cases[a-1][b-1] > 0){
			printf("\n\n** Current Location Risk: YELLOW ZONE !!! **");
		 	printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
		 	printf("\n--------------------------------------------------------------------------------------------------------");
		 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
		 	printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Terengganu() //Terengganu cases
{
	int a, b;
	int cases[8][21] =
	//  1   2   3   4	5	6	7	8	9	10	11	12	13	14	15	16	17  18  19  20  21
	{{ 14,  4,  0,  0,  0,  0,  6,  2,  4,  0,  0,  1,  0,  0,  1, 160,  0,  0,  1,  0,  0},	// Kuala Terengganu
	 {  0,  0,  0,  5,  1,  5,  0,  6,  1,  0,  0,  0, -1, -1, -1,  -1, -1, -1, -1, -1, -1},	// Kemaman 
	 { 13,  0,  0, 30,  2, 24, 14,  1,  2, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1},	// Dungun 
	 {  4,  0,  8,  3, 12, 14,  6,  6,  0,  1,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1},	// Besut 
	 {  0,  1,  3,  0,  0,  1,  1,  7, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1},	// Marang 
	 {  0,  0,  0,  0,  0,  0,  0,  1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1},	// Hulu Terengganu  
	 {  0,  0,  4,  6,  1,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1},	// Setiu
	 {  4,  9,  0,  0,  2,  5,  0, -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1}};	// Kuala Nerus
	 	
	if(state==13){
		if (district==1){
			printf("\n\n******************************************** DISTRICT / DAERAH : KUALA TERENGGANU **********************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bandar                   6.  Batu Burok          11.  Rengas                 16.  Serada            21.  Kepong   |\n");
			printf("   |  2.  Cabang Tiga              7.  Kuala Ibai          12.  Pengadang Buluh        17.  Paloh                           |\n");
			printf("   |  3.  Pekan Cabang Tiga        8.  Chendering          13.  Gelugur Raja           18.  Losong                          |\n");
			printf("   |  4.  Pulau-Pulau              9.  Bukit Besar         14.  Gelugur Kedai          19.  Kubang Parit                    |\n");
			printf("   |  5.  Tok Jamal               10.  Atas Tol            15.  Manir                  20.  Belara                          |\n");
			printf("   --------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==2){
			printf("\n\n**************************************** DISTRICT / DAERAH : KEMAMAN ******************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Binjai                4.  Kerteh                   7.  Banggol                10.  Tebak         |\n");
			printf("   |  2.  Hulu Jabor            5.  Kijal                    8.  Chukai                 11.  Hulu Chukai   |\n");
			printf("   |  3.  Bandi                 6.  Telok Kalong             9.  Kemasek                12.  Pasir Semut   |\n");
			printf("   ---------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==3){ 
			printf("\n\n********************************************* DISTRICT / DAERAH : DUNGUN *********************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Abang            3.  Jengai              5.  Kuala Dungun           7.  Sura                 9.  Paka   |\n");
			printf("   |  2.  Besol            4.  Jerangau            6.  Rasau                  8.  Hulu Paka                       |\n");
			printf("   ----------------------------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==4){
			printf("\n\n******************************************** DISTRICT / DAERAH : BESUT ********************************************\n");
	  		printf("   -------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bukit Kenak            5.  Keluang                  9.  Pasir Akar                  13.  Tembila     |\n");
			printf("   |  2.  Bukit Puteri           6.  Kerandang               10.  Pelagat                     14.  Tenang      |\n");
			printf("   |  3.  Jabi                   7.  Kubang Bemban           11.  Pengkalan Nangka            15.  Hulu Besut  |\n");
			printf("   |  4.  Kampung Raja           8.  Lubuk Kawah             12.  Kuala Besut                                  |\n");
			printf("   -------------------------------------------------------------------------------------------------------------\n");
		}
	
		else if (district==5){
			printf("\n\n************************************************** DISTRICT / DAERAH : MARANG ****************************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Merchang              3.  Jerong                           5.  Bukit Payong (Binjai Rendah)        7.  Alor Limbat  |\n");
			printf("   |  2.  Pulau Kerengga        4.  Bukit Payong (Wakaf Tapai)       6.  Bukit Payong (Pekan)                8.  Rusila       |\n");
			printf("   ----------------------------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==6){
			printf("\n\n************************************ DISTRICT / DAERAH : HULU TERENGGANU ***************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Hulu Berang             3.  Jenagor                 5.  Kuala Telemong              7.  Tanggol   |\n");
			printf("   |  2.  Hulu Telemong           4.  Kuala Berang            6.  Penghulu Diman              8.  Tersat    |\n");
			printf("   ----------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==7){
			printf("\n\n******************************** DISTRICT / DAERAH : SETIU ************************************\n");
	  		printf("   -----------------------------------------------------------------------------------------\n");
			printf("   |  1.  Pantai             3.  Hulu Setia           5.  Hulu Nerus            7.  Tasek  |\n");
			printf("   |  2.  Guntung            4.  Chalok               6.  Merang                           |\n");
			printf("   -----------------------------------------------------------------------------------------\n");
		}
	
		else if (district==8){
			printf("\n\n***************************************** DISTRICT / DAERAH : KUALA NERUS *******************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bukit Tunggal             3.  Bukit Chempaka            5.  Wakaf Tembusu          7.  Seberang Takir  |\n");
			printf("   |  2.  Mengabang Telipot         4.  Wakaf Chagak              6.  Tepoh                                      |\n");
			printf("   ---------------------------------------------------------------------------------------------------------------\n");
		}
			
	printf("\nPlease choose your zone: ");
	scanf("%d", &zone);
	
	while ((district == 1 && zone < 1) || (district == 1 && zone > 21)||(district == 2 && zone < 1) || (district == 2 && zone > 12)||
		   (district == 3 && zone < 1) || (district == 3 && zone > 9)||(district == 4 && zone < 1) || (district == 4 && zone > 15)||
		   (district == 5 && zone < 1) || (district == 5 && zone > 8)||(district == 6 && zone < 1) || (district == 6 && zone > 8)||
		   (district == 7 && zone < 1) || (district == 7 && zone > 7)||(district == 8 && zone < 1) || (district == 8 && zone > 7)){
      		printf("Error! Please re-enter your choice: ");
      		scanf("%d", &zone);
    }
		
		a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
		}
	 	 	
		else if (cases[a-1][b-1] > 0){
			printf("\n\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_KL() //Kuala Lumpur cases
{
	int a, b;
	int cases[4][9] =
	//  1     2		3	  4		5	  6	   7	8    9   						
	{{ 172,  182,  130,  214,   20, 137, 254,  -1,  -1},	// Kepong
	 {  81,  120,  433,  179,   34, 248, 122,  48,  72},	// Lembah Pantai 
	 { 205,  153,  125,   56,   75,  32, 171,  -1,  -1},	// Titiwangsa 
	 { 187,   80,  175,   72,   40,  41,  -1,  -1,  -1}};	// Cheras 
	
	if(state==14){
		if (district==1){
			printf("\n\n************************************* DISTRICT / DAERAH : KEPONG ***************************************\n");
	  		printf("   --------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Kepong                3.  Mont Kiara              5.  B.Damansara             7.  Sentul  |\n");
			printf("   |  2.  Manjalara             4.  Duta                    6.  Batu                                |\n");
			printf("   --------------------------------------------------------------------------------------------------\n");
		}
				
		else if (district==2){
			printf("\n\n******************************************** DISTRICT / DAERAH : LEMBAH PANTAI ********************************************\n");
	  		printf("   ---------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Bangsar           3.  Ibu Kota              5.  Salak               7.  Seputeh             9.  Bukit Jalil  |\n");
			printf("   |  2.  L.Pantai          4.  Brickfields           6.  Taman Desa          8.  Sri Petaling                         |\n");
			printf("   ---------------------------------------------------------------------------------------------------------------------\n");
		}

		else if (district==3){
			printf("\n\n********************************* DISTRICT / DAERAH : TITIWANGSA ***********************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------\n");
			printf("   |  1.  Setapak                3.  Semarak                 5.  Kg Baru            7.  Pandan  |\n");
			printf("   |  2.  Wangsa Maju            4.  Setiawangsa             6.  D.Keramat                      |\n");
			printf("   ----------------------------------------------------------------------------------------------\n");
		}
		
		else if (district==4){
			printf("\n\n*************************************************** DISTRICT / DAERAH : CHERAS ***************************************************\n");
	  		printf("   ----------------------------------------------------------------------------------------------------------------------------\n");
			printf("   |  1.  B.Tun Razak         2.  Sg Besi          3.  Alam Damai          4.  Pudu          5.  Cheras        6.  Connaught  |\n");
			printf("   ----------------------------------------------------------------------------------------------------------------------------\n");
		}
		
		printf("\nPlease choose your zone: ");
		scanf("%d", &zone);	
		
		while ((district == 1 && zone < 1) || (district == 1 && zone > 7)||(district == 2 && zone < 1) || (district == 2 && zone > 9)||
		   	  (district == 3 && zone < 1) || (district == 3 && zone > 7)||(district == 4 && zone < 1) || (district == 4 && zone > 6)){
      			printf("Error! Please re-enter your choice: ");
      			scanf("%d", &zone);
    	}
    	
    	a = district, b = zone;
		
		if (cases[a-1][b-1] >= 41){
	 		printf("\n\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
		}
	 	 	
		else if (cases[a-1][b-1] > 0){
			printf("\n\n** Current Location Risk: YELLOW ZONE !!! **");
		 	printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[a-1][b-1]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[a-1][b-1] == 0){
			printf("\n\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Labuan() //Labuan cases
{
	int cases[1] = {179};	
	
	if (state==15){		
		if (cases[0] >= 41){
	 		printf("\n\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[0]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
		}
	 	 	
		else if (cases[0] > 0){
			printf("\n\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[0]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[0] == 0){
			printf("\n\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void case_Putrajaya() //Putrajaya cases
{
	int cases[1] = {258};		
	
	if (state==16){
		if (cases[0] >= 41){
	 		printf("\n\n** Current Location Risk: RED ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[0]);
	 		printf("\n\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
	 		printf("\n--------------------------------------------------------------------------------------------------------\n");
		}
	 	 	
		else if (cases[0] > 0){
			printf("\n\n** Current Location Risk: YELLOW ZONE !!! **");
	 		printf("\nThere have been %d reported case(s) of COVID-19 in the last 14 days.", cases[0]);
	 		printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
		
		else if (cases[0] == 0){
			printf("\n\n** Current Location Risk: GREEN ZONE  **");
			printf("\n--------------------------------------------------------------------------------------------------------");
	 		printf("\nReported case is based on the source & potential spread of COVID-19 after detailed investigation by MOH.");
			printf("\n--------------------------------------------------------------------------------------------------------\n");	
		}
	}
}

void zone_cases() //All zone cases
{
	if (state == 1)  
		case_Johor();
		
	else if (state == 2)  
		case_Kedah();
		
	else if (state == 3)  
		case_Kelantan();
		
	else if (state == 4)  
		case_Melaka();
		
	else if (state == 5)  
		case_NegeriSembilan();
		
	else if (state == 6)  
		case_Pahang();
		
	else if (state == 7)  
		case_Penang();
		
	else if (state == 8)  
		case_Perak();
		
	else if (state == 9)  
		case_Perlis();
		
	else if (state == 10)  
		case_Sabah();
		
	else if (state == 11)  
		case_Sarawak();
		
	else if (state == 12)  
		case_Selangor();
		
	else if (state == 13)  
		case_Terengganu();
		
	else if (state == 14)  
		case_KL();
		
	else if (state == 15)  
		case_Labuan();
		
	else if (state == 16){
		case_Putrajaya();
	}
	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    	if (main_exit==1)
        	menu();
    	else
        	close();
	return;
}

void search_acc(void) //Search registered accounts
{
    FILE *ptr;
    int test=0;
    int choice;
    float time;
    ptr = fopen("record.dat","r");
    
    printf("\t\t\t\t\xB2\xB2\xB2\xB2\ SEARCH REGISTERED ACCOUNT(S) \xB2\xB2\xB2\xB2\n\n");
    printf("Do you want to check by\n1.IC No\n2.Name\n3.Back to Account Settings\nEnter your choice: ");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the IC Number(XXXXXX-XX-XXXX): ");
        scanf("%d-%d-%d",&check.ic_no1,&check.ic_no2,&check.ic_no3);

        while (fscanf(ptr,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf",&add.ic_no1,&add.ic_no2,&add.ic_no3,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.relation,&add.age,add.gender,add.address,&add.postcode,&add.phone)!=EOF)
        {
            if(add.ic_no1==check.ic_no1 && add.ic_no2==check.ic_no2 && add.ic_no1==check.ic_no1)
            {   
				system("cls");
                test=1;

                printf("\nIC No.: %d-%d-%d\nName: %s \nDOB: %d/%d/%d \nRelation: %d \nAge: %d \nGender: %s \nAddress: %s \nPostcode: %d \nPhone number: %.0lf \n\n",add.ic_no1,add.ic_no2,add.ic_no3,add.name,add.dob.day,add.dob.month,add.dob.year,add.relation,add.age,add.gender,add.address,add.postcode,add.phone);

            }
        }
    }
    else if (choice==2)
    {   
		printf("Enter the name: ");
        scanf(" %[^\n]s",&check.name);
        while (fscanf(ptr,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf",&add.ic_no1,&add.ic_no2,&add.ic_no3,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.relation,&add.age,add.gender,add.address,&add.postcode,&add.phone)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nIC No.: %d-%d-%d\nName: %s \nDOB: %d/%d/%d \nRelation: %d \nAge: %d \nGender: %s \nAddress: %s \nPostcode: %d \nPhone number: %.0lf \n\n",add.ic_no1,add.ic_no2,add.ic_no3,add.name,add.dob.day,add.dob.month,add.dob.year,add.relation,add.age,add.gender,add.address,add.postcode,add.phone);
            }
        }
    }
    else if (choice==3){
    	account_settings();
	}


    fclose(ptr);
     if(test!=1)
        {   
			system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    search_acc();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            	close();
            }

}

void view_list() //View registered accounts
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    
    printf("\t\t\t\t\xB2\xB2\xB2\xB2\ VIEW REGISTERED ACCOUNT(S) \xB2\xB2\xB2\xB2\n\n");
    printf("\nIC. NO.\t\tNAME\t\t\tADDRESS\t\t\t\tGENDER\t\tPHONE\n");

    while(fscanf(view,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf",&add.ic_no1,&add.ic_no2,&add.ic_no3,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.relation,&add.age,add.gender,add.address,&add.postcode,&add.phone)!=EOF)
       {
       	
           printf("\n%d-%d-%d\t %10s\t\t\t%10s\t\t%s\t\t%.0lf",add.ic_no1,add.ic_no2,add.ic_no3,add.name,add.address,add.gender,add.phone);
           test++;
           
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void remove_acc(void) //Remove accounts
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\t\t\t\t\xB2\xB2\xB2\xB2\ REMOVE EXISTING ACCOUNT \xB2\xB2\xB2\xB2\n\n");
    printf("Enter the IC no. of the customer you want to delete(XXXXXX-XX-XXXX):");
    scanf("%d-%d-%d",&rem.ic_no1,&rem.ic_no2,&rem.ic_no3);
    while (fscanf(old,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf",&add.ic_no1,&add.ic_no2,&add.ic_no3,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.relation,&add.age,add.gender,add.address,&add.postcode,&add.phone)!=EOF)
   {
        if(add.ic_no1!=rem.ic_no1&&add.ic_no2!=rem.ic_no2&&add.ic_no3!=rem.ic_no3)
            fprintf(newrec,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf\n",add.ic_no1,add.ic_no2,add.ic_no3,add.name,add.dob.month,add.dob.day,add.dob.year,add.relation,add.age,add.gender,add.address,add.postcode,add.phone);

        else
            {
				test++;
	            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    remove_acc();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {
			printf("\nEnter 1 to go to the main menu and 0 to exit:");
	        scanf("%d",&main_exit);
	        system("cls");
	        if (main_exit==1)
	            menu();
	        else
	            close();
        }

}

int hotline_choice(int choose) //Choose hotline-type
{
	  printf("\n\n\n\n\t\t\tLOADING NOMBOR HOTLINE");
    	for(i=0;i<=6;i++)
    	{
            fordelay(100000000);
            printf(".");
   		}
	system("cls");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\ NOMBOR HOTLINE \xB2\xB2\xB2\xB2\n\n");
    printf("Please select your desire hotline number\n");
    printf("1. Malaysia Hotline Number\n");
    printf("2. Nearby Clinic Number\n");
    printf("3. Back to Main Menu\n\n");
    printf("Please enter your choice: ");
    scanf("%d", &choose);
    if(choose == 3){
    	menu();
	}
    return choose;
}

void hotline_major() //Malaysia Hotline
{
	printf("Health Ministry’s Crisis Preparedness and Response Centre: \n");
    printf("**************************************************************\n");
    printf("			1. 03 88810200 \n");
    printf("			2. 03 88810600 \n");
    printf("			3. 03 88810700 \n\n");
    printf("	      Email address : cprc@moh.gov.my    \n");
    printf("**************************************************************\n");
    printf("\nEnter 1 to go to the main menu and 0 to exit:");
		    scanf("%d",&main_exit);
		    system("cls");
		    if (main_exit==1)
		       	 menu();	
		    else
		         close();
    return;
}

void Clinic_Hotline() //Choose Your Location(for nearby clinic recommendation)
{
	printf("------------------------------------------------------------------------------------------------------\n");
    printf("|  NO  | STATE             |  NO  | STATE            |  NO  | STATE          |  NO  | STATE          |\n");
    printf("|------|-------------------|------|------------------|------|----------------|------|----------------|\n");
    printf("|  1.  | Johor             |  2.  | Kedah            |  3.  | Kelantan       |  4.  | Melaka         |\n");
    printf("|  5.  | Negeri Sembilan   |  6.  | Pahang           |  7.  | Penang         |  8.  | Perak          |\n");
    printf("|  9.  | Perlis            |  10. | Sabah            |  11. | Sarawak        |  12. | Selangor       |\n");
    printf("|  13. | Terengganu        |  14. | Kuala Lumpur     |  15. | Labuan         |  16. | Putrajaya      |\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("Please choose your state: ");
    scanf("%d", &clinic_state_hotline);
    
    while (state < 0 || state > 16){
      printf("Invalid! Please re-enter your choice: \n");
      scanf("%d",&clinic_state_hotline);
    }

}

void Johor_Hotline() //Johor Hotline
{
	int y;
	
	if (clinic_state_hotline == 1){	
		printf("\n************************************* STATE / NEGERI : JOHOR *************************************\n");
		printf("   --------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Johor Bahru        4.  Kulai                 7.  Segamat             10.  Mersing   |\n");
		printf("   |  2.  Batu Pahat         5.  Muar                  8.  Pontian                            |\n"); 
		printf("   |  3.  Kluang             6.  Kota Tinggi           9.  Tangkak                            |\n");
    	printf("   --------------------------------------------------------------------------------------------\n");
    	printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    
		while (y < 1 || y > 10){
        	printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}
        
    switch (y){
    	case 1:    	// Johor Bahru
    		printf("\n\n----------------------------------------------------------------\n");
        	printf("| Wad B2, Hospital Permai                          07-231 1000 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        	
        case 2:    	// Batu Pahat
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Batu Pahat                      07-433 2544 |\n");
        	printf("| Klinik Kesihatan Senggarang                      07-429 4858 |\n");
        	printf("| Klinik Kesihatan Yong Peng                       07-467 5960 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        
        case 3:    	// Kluang 
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Jalan Mengkibol                 07-776 5343 |\n");
        	printf("| Klinik Kesihatan Simpang Renggam                 07-755 4143 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        	
        case 4:   	// Kulai
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Kulai Besar                     07-662 5255 |\n");
        	printf("| Klinik Kesihatan Kulai                           07-663 2662 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        
		case 5:   	// Muar
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Maharani                        06-953 9729 |\n");
        	printf("| Klinik Kesihatan Parit Jawa                      06-987 4252 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
		
		case 6:   	// Kota Tinggi
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Asrama Jururawat                                 07-883 1131 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        	
        case 7:   	// Segamat
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Segamat                         07-931 5155 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        
        case 8:  	 // Pontian
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Pekan Nanas                     07-699 1007 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        	
        case 9:   	// Tangkak 
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Payamas                         06-978 1861 |\n");
        	printf("| Klinik Kesihatan Sg Mati                         06-975 1054 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        	
        case 10:   	// Mersing 
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Jemaluang                       07-792 1271 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;	
	}
}

void Kedah_Hotline() //Kedah Hotline
{
    int y;
    
    if (clinic_state_hotline == 2){
    	printf("\n**************************************** STATE / NEGERI : KEDAH ****************************************\n");
		printf("   --------------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Kuala Muda          4.  Kubang Pasu          7.  Langkawi            10.  Padang Terap    |\n");
		printf("   |  2.  Kota Setar          5.  Baling               8.  Yan                 11.  Pokok Sena      |\n");
		printf("   |  3.  Kulim               6.  Pendang              9.  Sik                 12.  Bandar Baharu   |\n");
		printf("   --------------------------------------------------------------------------------------------------\n");	
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    
    	while (y < 0 || y > 12){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

	switch(y){
		case 1:			// Kuala Muda
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bukit Selambau                     04-419 3312 |\n");
			printf("| Klinik Kesihatan Bakar Arang                        04-422 0294 |\n");
			printf("| Klinik Kesihatan Kota Kuala Muda                    04-437 4225 |\n");
			printf("| Klinik Kesihatan Sg Lalang                          04-459 4127 |\n");
			printf("| Klinik Kesihatan Merbok                             04-457 2214 |\n");
			printf("| Klinik Kesihatan Bandar Sungai Petani               04-421 3355 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
	
		case 2:			// Kota Setar
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bandar Alor Setar                  04-730 8353 |\n");
			printf("| Klinik Kesihatan Simpang Kuala                      04-772 0853 |\n");
			printf("| Klinik Kesihatan Simpang Empat                      04-980 7214 |\n");
			printf("| Klinik Kesihatan Kuala Kedah                        04-762 1526 |\n");
			printf("| Klinik Kesihatan Alor Janggus                       04-730 1985 |\n");
			printf("| Klinik Kesihatan Jalan Putra                        04-730 1985 |\n");
			printf("| Klinik Kesihatan Langgar                            04-787 6648 |\n");
			printf("| Klinik Kesihatan Pokok Sena                         04-782 1355 |\n");
			printf("| Klinik Kesihatan Kota Sarang Semut                  04-787 6648 |\n");
			printf("| Klinik Kesihatan Datuk Kumbar                       04-730 6319 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 3:			// Kulim
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Taman Selasih                      04-491 7377 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 4:			// Kubang Pasu
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Ayer Hitam                         04-794 2101 |\n");
			printf("| Klinik Kesihatan Changlun                           04-924 1277 |\n");
			printf("| Klinik Kesihatan Laka Temin                         04-922 2560 |\n");
			printf("| Klinik Kesihatan Napoh                              04-916 4944 |\n");
			printf("| Klinik Kesihatan Tunjang                            04-929 1524 |\n");
			printf("| Klinik Kesihatan Banai                              04-917 0375 |\n");
			printf("| Klinik Kesihatan Kodiang                            04-925 0178 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 5:			// Baling
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Malau                              04-406 1700 |\n");
			printf("| Klinik Kesihatan Kupang                             04-476 6355 |\n");
			printf("| Klinik Kesihatan Parit Panjang                      04-476 1246 |\n");
			printf("| Klinik Kesihatan Tawar                              04-476 6308 |\n");
			printf("| Klinik Kesihatan Kuala Ketil                        04-416 3355 |\n");
			printf("| Klinik Kesihatan Kampung Lalang                     04-472 1613 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 6:			// Pendang 
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Pendang                            04-759 6412 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 7:			// Langkawi
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Kuah                               04-966 3490 |\n");
			printf("| Klinik Kesihatan Padang Masirat                     04-955 1355 |\n");
			printf("| Klinik Kesihatan Ayer Hangat                        04-959 1959 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 8:			// Yan
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Guar Cempedak                      04-468 4435 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
			
		case 9:			// Sik
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Jeniang                            04-464 1200 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 10:		// Padang Terap
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Kuala Nerang	                      04-786 6355 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
			
		case 11:		// Pokok Sena
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Not Available	                                                  |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 12:		// Bandar Baharu
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bandar Baharu                      05-717 8232 |\n");
			printf("| Klinik Kesihatan Lubuk Buntar                       04-407 7320 |\n");
			printf("| Klinik Kesihatan Serdang                            04-407 7355 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		}
}

void Kelantan_Hotline() //Kelantan Hotline
{
    int y;
    
    if (clinic_state_hotline == 3){
    	printf("\n*********************************** STATE / NEGERI : KELANTAN ***********************************\n");
		printf("   -------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Kota Bharu          4.  Bachok               7.  Kuala Krai          10.  Jeli     |\n");
		printf("   |  2.  Pasir Mas           5.  Tanah Merah          8.  Machang                           |\n");
		printf("   |  3.  Tumpat              6.  Pasir Puteh          9.  Gua Musang                        |\n");
		printf("   -------------------------------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    	
    	while (y < 0 || y > 10){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

    switch (y)
    {
		case 1:   		// Kota Bharu
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Kota Jembalt		               09-766 6733 |\n");
        	printf("| Klinik Kesihatan Perol	                       09-712 3354 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        
    	case 2:    		// Pasir Mas
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Meranti                         09-797 5211 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        	
        case 3:			// Tumpat
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Not Available	                                                  |\n");
			printf("-------------------------------------------------------------------\n");
			break;

        case 4:    		// Bachok 
        	printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Mahligai		                   09-783 4213 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        	
        case 5:			// Tanah Merah
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Not Available	                                                  |\n");
			printf("-------------------------------------------------------------------\n");
			break;

    	case 6:    		// Pasir Puteh
			printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Pasir Puteh		               09-786 9291 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
        	
        case 7:			// Kuala Krai 
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Not Available	                                                  |\n");
			printf("-------------------------------------------------------------------\n");
			break;

        case 8:   		// Machang
    		printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Labok		                   09-787 8533 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
				
    	case 9:   		// Gua Musang 
			printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Gua Musang                      09-912 1286 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
			
		case 10:  		 // Jeli
			printf("\n\n----------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Jeli		                       09-944 0333 |\n");
        	printf("----------------------------------------------------------------\n");
        	break;
    	}
}

void Melaka_Hotline() //Melaka Hotline
{
    int y;
    
    if (clinic_state_hotline == 4){
    	printf("\n************************ STATE / NEGERI : MELAKA ************************\n");
		printf("   -------------------------------------------------------------------\n");
		printf("   |  1.  Melaka Tengah        2.  Alor Gajah            3.  Jasin   |\n");
		printf("   -------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    		
    	while (y < 0 || y > 3){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

	switch(y){
		case 1:		// Melaka Tengah
			printf("\n\n----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Tengkera                        06-336 0173 |\n");
        	printf("| Klinik Kesihatan Seri Tanjung                    06-351 1333 |\n");
        	printf("| Klinik Kesihatan Ayer Keroh                      06-232 3330 |\n");
        	printf("| Klinik Kesihatan Kuala Sg. Baru                  06-387 6333 |\n");
        	printf("| Klinik Kesihatan Masjid Tanah                    06-384 2533 |\n");
			printf("----------------------------------------------------------------\n");
			break;
	
		case 2:		// Alor Gajah
			printf("\n\n----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Durian Tunggal                  06-553 1134 |\n");
			printf("| Klinik Kesihatan Rembia                          06-316 1076 |\n");
			printf("| Klinik Kesihatan Alor Gajah                      06-556 6235 |\n");
			printf("----------------------------------------------------------------\n");
			break;
		
		case 3:		// Jasin
			printf("\n\n----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Merlimau                        06-263 1533 |\n");
        	printf("| Klinik Kesihatan Simpang Bekoh                   06-523 6033 |\n");
			printf("----------------------------------------------------------------\n");
			break;
		}
}

void NegeriSembilan_Hotline() //Negeri Sembilan Hotline
{
    int y;
    
    if (clinic_state_hotline == 5){
    	printf("\n******************************** STATE / NEGERI : NEGERI SEMBILAN *******************************\n");
	  	printf("   -------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Seremban           3.  Port Dickson          5.  Kuala Pilah          7.  Jelebu   |\n");
		printf("   |  2.  Jempol             4.  Tampin                6.  Rembau                            |\n");
		printf("   -------------------------------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    	
    	while (y < 0 || y > 7){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

	switch(y){
		case 1:		// Seremban
			printf("\n\n-----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Nilai                            06-850 4013 |\n");
        	printf("| Klinik Kesihatan Senawang                         06-676 6000 |\n");
        	printf("| Klinik Kesihatan Seremban                         06-767 9267 |\n");
			printf("-----------------------------------------------------------------\n");
			break;
			
		case 2:		// Jempol
			printf("\n\n-----------------------------------------------------------------\n");
			printf("| Not Available                                                 |\n");
			printf("-----------------------------------------------------------------\n");
			break;
		
		case 3:		// Port Dickson
			printf("\n\n-----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Lukut                            06-651 1958 |\n");
        	printf("| Klinik Kesihatan Pasir panjang Jempol             06-458 1667 |\n");
        	printf("| Klinik Kesihatan Bahau                            06-454 1234 |\n");
        	printf("| Klinik Kesihatan Palong 4,5.6                     06-466 6433 |\n");
			printf("-----------------------------------------------------------------\n");
			break;
		
		case 4:		// Tampin
			printf("\n\n-----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Gemas                            07-948 2352 |\n");
			printf("| Klinik Kesihatan Gemencheh                        06-431 8304 |\n");
			printf("-----------------------------------------------------------------\n");
			break;
		
		case 5:		// Kuala Pilah
			printf("\n\n-----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Terachi                          06-488 7202 |\n");
			printf("| Klinik Kesihatan Juasseh                          06-498 1581 |\n");
			printf("-----------------------------------------------------------------\n");
			break;
		
		case 6:		// Rembau
			printf("\n\n-----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Rembau                           06-685 2010 |\n");
        	printf("| Klinik Kesihatan Astana Raja                      06-438 2401 |\n");
			printf("-----------------------------------------------------------------\n");
			break;
		
		case 7:		// Jerebu
			printf("\n\n-----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Pertang                          06-494 1287 |\n");
        	printf("| Klinik Kesihatan Simpang Durian                   06-491 4522 |\n");
        	printf("| Klinik Kesihatan Titi                             06-611 1398 |\n");
			printf("-----------------------------------------------------------------\n");
			break;
		}
}

void Pahang_Hotline() //Pahang Hotline
{
    int y;
    
    if (clinic_state_hotline == 6){
    	printf("\n**************************************** STATE / NEGERI : PAHANG ********************************************\n");
	 	printf("   -------------------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Kuantan            4.  Maran                 7.  Bera                 10.  Lipis               |\n");
		printf("   |  2.  Temerloh           5.  Rompin                8.  Raub                 11.  Cameron Highlands   |\n");
		printf("   |  3.  Bentong            6.  Pekan                 9.  Jerantut                                      |\n");
		printf("   -------------------------------------------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    	
    	while (y < 0 || y > 11){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

	switch(y){
		case 1:		// Kuantan
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Balok		            09-583 4533 |\n");
        	printf("| Klinik Kesihatan Beserah		            09-544 5633 |\n");
        	printf("| Klinik Kesihatan Bandar		            09-513 5571 |\n");
        	printf("| Klinik Kesihatan Indera Mahkota		    09-573 0373 |\n");
        	printf("| Klinik Kesihatan Kurnia		            09-536 1333 |\n");
        	printf("| Klinik Kesihatan Paya Besar		        09-549 8811 |\n");  	
        	printf("| Klinik Kesihatan Permatang Badak		    09-536 4626 |\n");
        	printf("| Klinik Kesihatan Jaya Gading		        09-573 6572 |\n");
        	printf("| Klinik Kesihatan Gambang		            09-548 4611 |\n");
        	printf("| Klinik Kesihatan Bkt Goh		            09-547 8355 |\n");
        	printf("| Klinik Kesihatan Sg Lembing		        09-541 1598 |\n");
			printf("---------------------------------------------------------\n");
			break;
	
		case 2:		// Temerloh
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Temerloh		            09-296 1275 |\n");
        	printf("| Klinik Kesihatan Tanjung Lalang		    09-296 1152 |\n");
        	printf("| Klinik Kesihatan Bandar Mentakab		    09-296 1152 |\n");
        	printf("| Klinik Kesihatan Kuala Krau		        09-286 1242 |\n");
        	printf("| Klinik Kesihatan Sanggang		            09-284 6333 |\n");
        	printf("| Klinik Kesihatan Kerdau		            09-284 7003 |\n");
        	printf("| Klinik Kesihatan Lanchang		            09-280 3233 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 3:		// Bentong
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bentong	                09-222 0134 |\n");
        	printf("| Klinik Kesihatan Karak	                09-231 1245 |\n");
        	printf("| Klinik Kesihatan Mempaga	                09-237 7654 |\n");
        	printf("| Klinik Kesihatan Simpang Pelangai	        09-245 0755 |\n");
        	printf("| Klinik Kesihatan Chemomoi	                09-1299 744 |\n");
        	printf("| Klinik Kesihatan Telemong	                09-239 9972 |\n");
        	printf("| Klinik Kesihatan Lurah Bilut	            09-237 7333 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 4:		// Maran
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Maran	                09-477 1333 |\n");
        	printf("| Klinik Kesihatan Pekan Tajau	            09-477 4780 |\n");
        	printf("| Klinik Kesihatan Chenor	                09-299 5391 |\n");
        	printf("| Klinik Kesihatan Pekan Awah	            09-298 6333 |\n");
        	printf("| Klinik Kesihatan Jengka 2	                09-467 4320 |\n");
        	printf("| Klinik Kesihatan Jengka 22	            09-486 4423 |\n");
        	printf("| Klinik Kesihatan Bandar Jengka	        09-467 7198 |\n");
        	printf("| Klinik Kesihatan Jengka 7	                09-467 1566 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 5:		// Rompin
			printf("\n\n-----------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Rompin	                        09-414 0333 |\n");
        	printf("| Klinik Kesihatan Tanjung Gemok	                09-794 3516 |\n");
        	printf("| Klinik Kesihatan Tekek	                        09-419 1880 |\n");
        	printf("| Klinik Kesihatan Leban Chondong	                09-414 9237 |\n");
        	printf("| Klinik Kesihatan Bukit Ibam	                    09-445 7298 |\n");
        	printf("| Klinik Kesihatan Bandar Tun Abdul Razak	        09-445 7297 |\n");
        	printf("| Klinik Kesihatan Perantau Damai	                09-443 1333 |\n");
        	printf("| Klinik Kesihatan Chanis	                        09-447 1106 |\n");
        	printf("| Klinik Kesihatan Perwira Jaya	                    09-437 1176 |\n");
			printf("-----------------------------------------------------------------\n");
			break;
		
		case 6:		// Pekan
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bandar Pekan             09-421 1710 |\n");
        	printf("| Klinik Kesihatan Peramu Jaya              09-426 9609 |\n");
        	printf("| Klinik Kesihatan Chini                    09-456 6333 |\n");
        	printf("| Klinik Kesihatan Nenasi                   09-418 1233 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 7:		// Bera
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Padang Luas              09-255 2062 |\n");
        	printf("| Klinik Kesihatan Bandar 32                09-246 1988 |\n");
        	printf("| Klinik Kesihatan Purun                    09-248 1585 |\n");
        	printf("| Klinik Kesihatan Triang                   09-255 5333 |\n");
        	printf("| Klinik Kesihatan Kemayan                  09-240 9715 |\n");
        	printf("| Klinik Kesihatan Bukit Mendi              09-245 0161 |\n");
        	printf("| Klinik Kesihatan Tembangau                06-468 5730 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 8:		// Raub
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Dong		                09-365 8355 |\n");
        	printf("| Klinik Kesihatan Jeruas		            09-365 7398 |\n");
        	printf("| Klinik Kesihatan Tersang	                09-340 3086	|\n");
        	printf("| Klinik Kesihatan Lembah Klau		        09-368 8333 |\n");
			printf("---------------------------------------------------------\n");
			break;
			
		case 9:		// Jerantut
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Jengka 8	                09-208 1554 |\n");
        	printf("| Klinik Kesihatan Damak	                09-268 1425 |\n");
        	printf("| Klinik Kesihatan Sg Tekam Utara	        09-481 1526 |\n");
        	printf("| Klinik Kesihatan Bandar Jerantut	        09-266 2202 |\n");
        	printf("| Klinik Kesihatan Kuala Tembeling	        09-308 6033 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 10:	// Lipis
			printf("\n\n------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Benta                       09-323 9211 |\n");
        	printf("| Klinik Kesihatan Padang Tengku               09-329 1533 |\n");
        	printf("| Klinik Kesihatan Bukit Betong                09-329 1212 |\n");
        	printf("| Klinik Kesihatan Merapoh                     09-912 2377 |\n");
        	printf("| Klinik Kesihatan Mela                        09-312 9424 |\n");
        	printf("| Klinik Kesihatan Sungai Koyan                09-340 1533 |\n");
        	printf("| Klinik Kesihatan Jerkoh                      09-312 9424 |\n");
        	printf("| Klinik Kesihatan Ibu Anak(KKIA) Lipis        09-513 2055 |\n");
			printf("------------------------------------------------------------\n");
			break;
		
		case 11:	// Cameron Highlands
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Ringlet		            05-495 6581 |\n");
			printf("| Klinik Kesihatan Kg. Raja		            09-695 3853 |\n");
			printf("| Klinik Kesihatan Tanah Rata		        05-491 1257 |\n");
			printf("---------------------------------------------------------\n");
			break;
		}
}

void Penang_Hotline() //Penang Hotline
{
    int y;
    
    if (clinic_state_hotline == 7){
    	printf("\n******************************************* STATE / NEGERI : PENANG **********************************************\n");
	  	printf("   ------------------------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Timur Laut Pulau Pinang           3.  Seberang Perai Utara             5.  Seberang Perai Selatan   |\n");
		printf("   |  2.  Seberang Perai Tengah             4.  Barat Daya Pulau Pinang                                       |\n");
		printf("   ------------------------------------------------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    		
    	while (y < 0 || y > 5){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

	switch(y){
		case 1:		// Timur Laut Pulau Pinang
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Jalan Perak		        04-281 8900 |\n");
			printf("---------------------------------------------------------\n");
			break;
	
		case 2:		// Seberang Perai Tengah
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Seberang Jaya		    04-390 0264 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 3:		// Seberang Perai Utara
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Sungai Dua		        04-642 2201 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 4:		// Barat Daya Pulau Pinang
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bayan Baru               04-642 5102 |\n");
			printf("---------------------------------------------------------\n");
			break;
			
		case 5:		// Seberang Perai Selatan
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bukit Panchor		    04-593 5892 |\n");
			printf("---------------------------------------------------------\n");
			break;
		}
}

void Perak_Hotline() //Perak Hotline
{
    int y;
    
    if (clinic_state_hotline == 8){
    	printf("\n********************************************** STATE / NEGERI : PERAK *************************************************\n");
	  	printf("   -----------------------------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Kinta                          4.  Hilir Perak            7.  Kuala Kangsar            10.  Kampar       |\n");
		printf("   |  2.  Larut, Matang dan Selama       5.  Kerian                 8.  Perak Tengah             11.  Muallim      |\n");
		printf("   |  3.  Manjung                        6.  Batang Padang          9.  Hulu Perak               12.  Bagan Datuk  |\n");
		printf("   -----------------------------------------------------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    	
		while (y < 0 || y > 12){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}	

	switch(y){
		case 1:		// Kinta
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Jelapang	                05-526 3834 |\n");
			printf("| Klinik Kesihatan Greentown	            05-253 0801 |\n");
			printf("---------------------------------------------------------\n");
			break;
			
		case 2:		// Laut, Matang Dan Selama
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Simpang		            05-849 1466 |\n");
			printf("---------------------------------------------------------\n");
			break;
			
		case 3:		// Manjung
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Sitiawan Mualim		    05-691 4355 |\n");
			printf("| Klinik Kesihatan Tanjung Malim		    05-459 6333 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 4:		// Hilir Perak
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Teluk Intan              05-621 4020 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 5:		// Kerian
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bagan Serai              05-721 5355 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 6:		// Batang Padang
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Tap                      	-	    |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 7:		// Kuala Kangsar
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Padang Rengas            05-758 4355 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 8:		// Perak Tengah
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Seri Iskandar		    05-373 1903 |\n");
			printf("---------------------------------------------------------\n");
			break;
			
		case 9:		// Hulu Perak
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Lenggong	       	        05-767 7355 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 10:	// Kampar
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Kampar                   05-465 9197 |\n");
			printf("---------------------------------------------------------\n");
			break;
			
		case 11:	// Muallim
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Sitiawan Mualim		    05-691 4355 |\n");
			printf("---------------------------------------------------------\n");
			break;
			
		case 12:	// Bagan Datuk
			printf("\n\n---------------------------------------------------------\n");
			printf("| Not Available		                                    |\n");
			printf("---------------------------------------------------------\n");
			break;
		}
}

void Perlis_Hotline() //Perlis Hotline
{ 
	if (clinic_state_hotline == 9){
    	printf("\n\n---------------------------------------------------------\n");
    	printf("| Klinik Kesihatan Beseri                   04-938 1355 |\n");
		printf("| Klinik Kesihatan Kangar                   04-977 9043 |\n");
		printf("| Klinik Kesihatan Padang Besar             04-949 0333 |\n");
		printf("| Klinik Kesihatan Simpang Empat            04-762 1526 |\n");
		printf("---------------------------------------------------------\n");
	}
}

void Sabah_Hotline() //Sabah Hotline
{
    int y;
    
    if (clinic_state_hotline == 10){
    	printf("\n************************************************ STATE / NEGERI : SABAH ***************************************************\n");
	  	printf("   ---------------------------------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Kota Kinabalu        6.  Kinabatangan       11.  Tuaran              16.  Beaufort         21.  Tambunan     |\n");
		printf("   |  2.  Tawau                7.  Semporna           12.  Ranau               17.  Kunak            22.  Tongod       |\n");
		printf("   |  3.  Sandakan             8.  Papar              13.  Kota Belud          18.  Tenom            23.  Sipitang     |\n");
		printf("   |  4.  Lahad Datu           9.  Penampang          14.  Kudat               19.  Putatan          24.  Nabawan      |\n");
		printf("   |  5.  Keningau            10.  Beluran            15.  Kota Marudu         20.  Pitas            25.  Kuala Penyu  |\n");
		printf("   ---------------------------------------------------------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    	
    	while (y < 0 || y > 25){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

    switch (y){
	    case 1:   // Kota Kinabalu
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Inanam                 088-421694 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 2:   // Tawau
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Merotai Besar	      089-902601 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 3:   // Sandakan
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Sandakan               089-225800 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 4:   // Lahad Datu
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Lahad Datu	          089-885110 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 5:   // Keningau
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Apin-Apin		      087-337371 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 6:   // Kinabatangan 
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Bukit Garam            089-562151 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 7:   // Semporna
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Semporna	              089-781695 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 8:   // Papar
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Kinarut                088-750331 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 9:   // Penampang
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Penampang  	          088-717978 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 10:   // Beluran
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Pejabat Kesihatan Kuala Sapi            089-552602 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 11:   // Tuaran
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Kiulu	              088-782830 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	
	    case 12:   // Ranau
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Kundasang              088-889722 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 13:   // Kota Belud
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Jawi-Jawi		      088-976001 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 14:  // Kudat
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Karakit		          088-671526 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 15:  // Kota Marudu
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Tandek                 088-661533 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 16:  // Beaufort
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Kilnik kesihatan Kota Klias		      087-881143 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 17:  // Kunak
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Daerah Kunak	          089-851733 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 18:  // Tenom
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Kemabong	              087-736896 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 19:  // Putatan
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Putatan		         088-765 704 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 20:  // Pitas
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Telaga		          088-638005 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 21:  // Tambunan
	        printf("\n\n------------------------------------------------------\n");
	        printf("| Klinik Kesihatan Sunsuron	              089-892002 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 22:  // Tongod
	        printf("\n\n------------------------------------------------------\n");
	        printf("Klinik Kesihatan Tongod	                  089-719004 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 23:  // Sipitang
	        printf("\n\n------------------------------------------------------\n");
	        printf("Klinik Kesihatan Meligan	              087-821066 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 24:  // Nabawan 
	        printf("\n\n------------------------------------------------------\n");
	        printf("Klinik Kesihatan Nabawan		          087-366199 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	        
	    case 25:  // Kuala Penyu 
	        printf("\n\n------------------------------------------------------\n");
	        printf("Klinik Kesihatan Menumbok	              087-831066 |\n");
	        printf("------------------------------------------------------\n");
	        break;
	    }
}

void Sarawak_Hotline() //Sarawak Hotline
{
    int y;

	if (clinic_state_hotline == 11){
		printf("\n*********************************** STATE / NEGERI : SARAWAK **************************************\n");
	  	printf("   -------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Kuching             4.  Bintulu              7.  Sri Aman           10.  Kapit     |\n");
		printf("   |  2.  Miri                5.  Serian               8.  Betong             11.  Limbang   |\n");
		printf("   |  3.  Sibu                6.  Samarahan            9.  Sarikei            12.  Mukah     |\n");
		printf("   -------------------------------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    	
    	while (y < 0 || y > 12){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}
	
	switch(y){
		case 1:		// Kuching
			printf("\n\n---------------------------------------------------------\n");
			printf("| Kompleks Belia dan Sukan		            082-232 029 |\n");
			printf("---------------------------------------------------------\n");
			break;
	
		case 2:		// Miri
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Miri                 	085-412 322 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 3:		// Sibu
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Lanang                   084-210 433 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 4:		// Bintulu
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bintulu		            086-858 200 |\n");
        	printf("| Klinik Kesihatan Tatau		            086-584 289 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 5:		// Serian
			printf("\n\n---------------------------------------------------------\n");
			printf("| Institut Latihan KKM Serian		         082-874089 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 6:		// Samarahan
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Kota Samarahan           082-671 285 |\n");
        	printf("| Klinik Kesihatan Sebuyau                  083-467 126 |\n");
       	 	printf("| Klinik Kesihatan Asajaya                  082-828 124 |\n");
        	printf("| Klinik Kesihatan Sadong Jaya              082 821 084 |\n");
        	printf("| Klinik Kesihatan Munggu Lallang           083-565 101 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 7:		// Sri Aman
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Sri Aman		            083-327 769 |\n");
        	printf("| Klinik Kesihatan Lubok Antu	            083-584 105 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 8:		// Betong
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Mid Layar		             -      |\n");
        	printf("| Klinik Kesihatan Debak	                083-464 570 |\n");
        	printf("| Klinik Kesihatan Pusa	                    083-465 155 |\n");
        	printf("| Klinik Kesihatan Beladin	                083-466 748 |\n");
        	printf("| Klinik Kesihatan Roban	                083-427 244 |\n");
        	printf("| Klinik Kesihatan Kabong	                083-411 211 |\n");
			printf("---------------------------------------------------------\n");
			break;
			
		case 9:		// Sarikei
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bintangor	                      084-693 333 |\n");
        	printf("| Emergency & Trauma Depart. Hospital Sarikei	      084-653 333 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 10:	// Kapit
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Kapit       	            084-799 661 |\n");
        	printf("| Klinik Kesihatan Song        	            084-777 634 |\n");
        	printf("| Klinik Kesihatan Sg Asap                       -      |\n");
        	printf("| Klinik Kesihatan Belaga        	        086-461 323 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 11:	// Limbang
			printf("\n\n---------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Kuala Lawas         	                085-284 871 |\n");
        	printf("| Emergency & Trauma Depart. Hospital Limbang         	085-211 200 |\n");
			printf("---------------------------------------------------------------------\n");
			break;
		
		case 12:	// Mukah
			printf("\n\n---------------------------------------------------------------------\n");
			printf("| Emergency & Trauma Depart. Hospital Mukah             084-871 333 |\n");
			printf("---------------------------------------------------------------------\n");
			break;
		}
}

void Selangor_Hotline() //Selangor Hotline
{
    int y;
    
    if (clinic_state_hotline == 12){
    	printf("\n********************************************* STATE / NEGERI : SELANGOR ************************************************\n");
	  	printf("   ------------------------------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Petaling           3.  Klang           5.  Kuala Langat       7.  Kuala Selangor       9.  Sabak Bernam   |\n");
		printf("   |  2.  Hulu Langat        4.  Gombak          6.  Sepang             8.  Hulu Selangor                           |\n");
		printf("   ------------------------------------------------------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    		
    	while (y < 0 || y > 9){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

	switch(y){
		case 1:		// Petaling
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Kelana Jaya		                 03-7804 5001 |\n");
			printf("| Klinik Kesihatan Taman Medan		                 03-7781 9001 |\n");
			printf("| Klinik Kesihatan Puchong		                     03-8051 2815 |\n");
			printf("| Klinik Kesihatan Seksyen 19 Shah Alam		         03-5541 3570 |\n");
			printf("| Klinik Kesihatan Seksyen 7 Shah Alam		         03-5518 6531 |\n");
			printf("| Klinik Kesihatan Seri Kembangan		             03-8945 5929 |\n");
			printf("-------------------------------------------------------------------\n");
			break;

		case 2:		// Hulu Langat
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bandar Tun Hussein Onn            03-9081 3792 |\n");
        	printf("| Klinik Kesihatan Semenyih                          03-8723 8355 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 3:		// Klang
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bandar Botanik		             03-3324 4260 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 4:		// Gombak
			printf("\n\n-------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Sg Buloh                          03-6140 1293 |\n");
        	printf("| KK Selayang Baru                                   03-6187 8564 |\n");
        	printf("| Klinik Kesihatan AU2                               03-4251 9005 |\n");
        	printf("| Klinik Kesihatan Taman Ehsan                       03-6272 7471 |\n");
        	printf("| Klinik Kesihatan Rawang                            03-6091 9055 |\n");
        	printf("| Klinik Kesihatan Gombak Setia                      03-6177 0305 |\n");
        	printf("| Klinik Kesihatan Kuang                             03-6037 1355 |\n");
        	printf("| Klinik Kesihatan Batu Arang                        03-6035 2287 |\n");
        	printf("| KK Hulu Kelang                                     03-4105 6640 |\n");
        	printf("| Klinik Kesihatan Batu 8                            03-6188 9704 |\n");
			printf("-------------------------------------------------------------------\n");
			break;
		
		case 5:		// Kuala Langat
			printf("\n\n--------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Jenjarom		                      03-3191 3066 |\n");
        	printf("| Klinik Kesihatan Teluk Datuk	                      03-3187 1117 |\n");
        	printf("| Klinik Kesihatan Teluk Panglima Garang		      03-3122 7433 |\n");
        	printf("| Klinik Kesihatan Sijangkang	                      03-3122 6686 |\n");
        	printf("| Klinik Kesihatan Kebun Baru		                  03-3122 0943 |\n");
        	printf("| Klinik Kesihatan Bandar	                          03-3120 1333 |\n");
        	printf("| Klinik Kesihatan Tg. Sepat		                  03-3197 2044 |\n");
        	printf("| Klinik Kesihatan Bukit Changgang	                  03-3149 1355 |\n");
			printf("--------------------------------------------------------------------\n");
			break;
		
		case 6:		// Sepang
			printf("\n\n--------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Salak    		                  03-8706 9001 |\n");
        	printf("| Klinik Kesihatan Sg Pelek    		                  03-3141 1242 |\n");
        	printf("| Klinik Kesihatan Dengkil   		                  03-8768 6355 |\n");
			printf("--------------------------------------------------------------------\n");
			break;
		
		case 7:		// Kuala Selangor
			printf("\n\n--------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bestari Jaya		                  03-3271 9151 |\n");
        	printf("| Klinik Kesihatan Kuala selangor		              03-3289 1142 |\n");
        	printf("| Klinik Kesihatan Jeram		                      03-3264 7075 |\n");
        	printf("| Klinik Kesihatan Ijok		                          03-3279 1167 |\n");
			printf("--------------------------------------------------------------------\n");
			break;
		
		case 8:		// Hulu Selangor
			printf("\n\n--------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bandar Tun Hussein Onn             03-9081 3792 |\n");
        	printf("| Klinik Kesihatan Semenyih                           03-8723 8355 |\n");
        	printf("| Klinik Kesihatan Bangi                              03-8925 8707 |\n");
        	printf("| Klinik Kesihatan Batu 14                            03-9021 1414 |\n");
			printf("--------------------------------------------------------------------\n");
			break;
			
		case 9:		// Sabak Bernam
			printf("\n\n--------------------------------------------------------------------\n");
			printf("| Klinik Kesihatan Simpang Lima                   	  03-3224 2823 |\n");
			printf("--------------------------------------------------------------------\n");
			break;
		}
}

void Terengganu_Hotline() //Terengganu Hotline
{
    int y;
    
    if (clinic_state_hotline == 13){
    	printf("\n************************************** STATE / NEGERI : TERENGGANU ******************************************\n");
	  	printf("   -------------------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Kuala Terengganu         3.  Dungun            5.  Marang                    7.  Setiu         |\n");
		printf("   |  2.  Kemaman                  4.  Besut             6.  Hulu Terengganu           8.  Kuala Nerus   |\n");
		printf("   -------------------------------------------------------------------------------------------------------\n");   		
    	printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    	
    	while (y < 0 || y > 8){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

	switch(y){
		case 1:		// Kuala Terengganu
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Manir                    09-615 1447 |\n");
			printf("---------------------------------------------------------\n");
			break;
	
		case 2:		// Kemaman
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Batu 2 1/2               09-858 1540 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 3:		// Dungun
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Ketengah Jaya		    09-820 0233 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 4:		// Besut
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Padang Luas              09-255 2062 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 5:		// Marang
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Bukit Payong		        09-619 1333 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 6:		// Hulu Terengganu
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Kuala Berang		        09-681 1597 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 7:		// Setiu
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Rahmat                   09-609 7033 |\n");
			printf("---------------------------------------------------------\n");
			break;
		
		case 8:		// Kuala Nerus
			printf("\n\n---------------------------------------------------------\n");
			printf("| Klinik Kesihatan Batu Rakit               09-669 3331 |\n");
			printf("---------------------------------------------------------\n");
			break;
		}
}

void KL_Hotline() //Kuala Lumpur Hotline
{
	int y;
	
	if (clinic_state_hotline == 14){
		printf("\n***************************************** STATE / NEGERI : KUALA LUMPUR *********************************************\n");
	  	printf("   ---------------------------------------------------------------------------------------------------------------\n");
		printf("   |  1.  Kepong              2.  Lembah Pantai                3.  Titiwangsa               4.  Cheras           |\n");
		printf("   ---------------------------------------------------------------------------------------------------------------\n");
		printf("\nPlease choose your district: ");
    	scanf("%d", &y);
    		
    	while (y < 0 || y > 12){
       		printf("\nInvalid! Please re-enter your choice: ");
        	scanf("%d", &y);
		}
	}

    switch(y){
		case 1:    // Kepong
        	printf("\n\n------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Jinjang	     	          03-6258 3355 |\n");
        	printf("------------------------------------------------------------\n");
        	break;
        	
        case 2:	  // Lembah Pantai
        	printf("\n\n------------------------------------------------------------\n");
        	printf("| Not Available	     	                                   |\n");
        	printf("------------------------------------------------------------\n");
        	break;

        case 3:   // Titiwangsa
			printf("\n\n------------------------------------------------------------\n");
        	printf("| Klinik Kesihatan Kuala Lumpur               03-2618 3200 |\n");
        	printf("----------------------------------------------------------- \n");
        	break;
				
    	case 4:   // Cheras
			printf("\n\n------------------------------------------------------------\n");
        	printf("| Pejabat Kesihatan - drive through	          03-7884 0400 |\n");
        	printf("------------------------------------------------------------\n");
        	break;    
    }
}

void Labuan_Hotline() //Labuan Hotline
{
    if (clinic_state_hotline == 15){
    	printf("-----------------------------------------------------------|\n");
    	printf("| Klinik Kesihatan Labuan                       087-596888 |\n");
		printf("-----------------------------------------------------------|\n");
	}
}

void Putrajaya_Hotline() //Putrajaya Hotline
{
	if (clinic_state_hotline == 16){
		printf("\n\n-----------------------------------------------------------------------------\n");
		printf("| Klinik Kesihatan Putrajaya Presint 9                         03-8888 3057 |\n");
		printf("| Pejabat Kesihatan Putrajaya - drive through                  03-8885 0400 |\n");
		printf("-----------------------------------------------------------------------------\n");	
	}
}

void Hotline() //hotline choice
{
    if (clinic_state_hotline == 1)
		Johor_Hotline();
		
	if (clinic_state_hotline == 2)
		Kedah_Hotline();
		
	if (clinic_state_hotline == 3)
		Kelantan_Hotline();
			
    if (clinic_state_hotline == 4)
		Melaka_Hotline();
		
	if (clinic_state_hotline == 5)
		NegeriSembilan_Hotline();
		
	if (clinic_state_hotline == 6)
		Pahang_Hotline();
		
	if (clinic_state_hotline == 7)
		Penang_Hotline();
		
	if (clinic_state_hotline == 8)
		Penang_Hotline();
		
    if (clinic_state_hotline == 9)
		Perlis_Hotline();
		
	if (clinic_state_hotline == 10)
		Sabah_Hotline();
		
	if (clinic_state_hotline == 11)
		Sarawak_Hotline();
		
	if (clinic_state_hotline == 12)
		Selangor_Hotline();
		
	if (clinic_state_hotline == 13)
		Terengganu_Hotline();
		
	if (clinic_state_hotline == 14)
		KL_Hotline();
		
	if (clinic_state_hotline == 15)
		Labuan_Hotline();
		
	if (clinic_state_hotline == 16)
		Putrajaya_Hotline();
		
	printf("\nEnter 1 to go to the main menu and 0 to exit:");
			    scanf("%d",&main_exit);
			    system("cls");
			    if (main_exit==1)
			       	 menu();	
			    else
			         close();
    return;
}

void self_test() //Self test
{
  printf("\n\n\n\n\t\t\tLOADING UJIAN COVID-19 DI RUMAH");
    	for(i=0;i<=6;i++)
    	{
            fordelay(100000000);
            printf(".");
   		}
	system("cls");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\ UJIAN COVID-19 DI RUMAH \xB2\xB2\xB2\xB2\n\n");
  printf("*****************");
  printf("* Questionnaire *");
  printf("*****************");
  printf("\n\n");
  printf("1. Do you have a fever?/Adakah anda mengalami deman?\n");
  printf("Enter 'Y' for YES and 'N' for NO.\n");
  scanf("%s", &choice1);
  printf("\n");
  while (choice1 != 'Y' && choice1 != 'N'){
    printf("Error! Please enter again!\n");
    printf("1. Do you have a fever?/Adakah anda mengalami deman?\n");
    printf("Enter 'Y' for YES and 'N' for NO.\n");
    scanf("%s", &choice5);
    printf("\n");
  }

  printf("2. Are you coughing?/Adakah anda mengalami masalah batuk?\n");
  printf("Enter 'Y' for YES and 'N' for NO.\n");
  scanf("%s", &choice2);
  printf("\n");
  while (choice2 != 'Y' && choice2 != 'N'){
    printf("Error! Please enter again!\n");
    printf("2. Are you coughing?/Adakah anda mengalami masalah batuk?\n");
    printf("Enter 'Y' for YES and 'N' for NO.\n");
    scanf("%s", &choice2);
    printf("\n");
  }

  printf("3. Are you experiencing shortness off breath?/Adakah anda mengalami masalah sesak nafas?\n");
  printf("Enter 'Y' for YES and 'N' for NO.\n");
  scanf("%s", &choice3);
  printf("\n");
  while (choice3 != 'Y' && choice3 != 'N'){
    printf("Error! Please enter again!\n");
    printf("3. Are you experiencing shortness off breath?/Adakah anda mengalami masalah sesak nafas?\n");
    printf("Enter 'Y' for YES and 'N' for NO.\n");
    scanf("%s", &choice3);
    printf("\n");
  }

  printf("4. Have you travelled to any country outside Malaysia for the past 14 days?/Adakah anda berkunjung ke luar negara dalam tempoh 14 hari lepas?\n");
  printf("Enter 'Y' for YES and 'N' for NO.\n");
  scanf("%s", &choice4);
  printf("\n");
  while (choice4 != 'Y' && choice4 != 'N'){
    printf("Error! Please enter again!\n");
    printf("4. Have you travelled to any country outside Malaysia for the past 14 days?/Adakah anda berkunjung ke luar negara dalam tempoh 14 hari lepas?\n");
    printf("Enter 'Y' for YES and 'N' for NO.\n");
    scanf("%s", &choice4);
    printf("\n");
  }

    printf("5. Have you had a close contact with a COVID-19 patient in the last 14 days? (If yes,please fill in the following page)/Adakah anda berhubung rapat dengan seseorang yang positif COVID-19 dalam tempoh 14 hari yang lepas?(Jika anda menjawab ya, sila isikan halaman berikut)\n");
    printf("Enter 'Y' for YES and 'N' for NO.\n");
    scanf("%s", &choice5);
    printf("\n");
    while (choice5 != 'Y' && choice5 != 'N'){
    printf("Error! Please enter again!\n");
    printf("5. Have you had a close contact with a COVID-19 patient in the last 14 days? (If yes,please fill in the following page)/Adakah anda berhubung rapat dengan seseorang yang positif COVID-19 dalam tempoh 14 hari yang lepas?(Jika anda menjawab ya, sila isikan halaman berikut)\n");
    printf("Enter 'Y' for YES and 'N' for NO.\n");
    scanf("%s", &choice5);
    printf("\n");
    system("cls");
	}
}

void hotline_9() //Hotline output
{
	printf("\n\nNearest Local Health Contacts:\n\n");
	
	if(state==1)
	{
		switch (district){
			case 1:    	// Johor Bahru
    			printf("\n\n----------------------------------------------------------------\n");
        		printf("| Wad B2, Hospital Permai                          07-231 1000 |\n");
        		printf("----------------------------------------------------------------\n");
        		break;
        	
        	case 2:    	// Batu Pahat
        		printf("\n\n----------------------------------------------------------------\n");
        		printf("| Klinik Kesihatan Batu Pahat                      07-433 2544 |\n");
        		printf("| Klinik Kesihatan Senggarang                      07-429 4858 |\n");
        		printf("| Klinik Kesihatan Yong Peng                       07-467 5960 |\n");
        		printf("----------------------------------------------------------------\n");
        		break;
        
        	case 3:    	// Kluang 
        		printf("\n\n----------------------------------------------------------------\n");
        		printf("| Klinik Kesihatan Jalan Mengkibol                 07-776 5343 |\n");
        		printf("| Klinik Kesihatan Simpang Renggam                 07-755 4143 |\n");
        		printf("----------------------------------------------------------------\n");
        		break;
        	
        	case 4:   	// Kulai
        		printf("\n\n----------------------------------------------------------------\n");
        		printf("| Klinik Kesihatan Kulai Besar                     07-662 5255 |\n");
        		printf("| Klinik Kesihatan Kulai                           07-663 2662 |\n");
        		printf("----------------------------------------------------------------\n");
        		break;
        
			case 5:   	// Muar
	        	printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Maharani                        06-953 9729 |\n");
	        	printf("| Klinik Kesihatan Parit Jawa                      06-987 4252 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
		
			case 6:   	// Kota Tinggi
	        	printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Asrama Jururawat                                 07-883 1131 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
        	
	        case 7:   	// Segamat
	        	printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Segamat                         07-931 5155 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
	        
	        case 8:  	 // Pontian
	        	printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Pekan Nanas                     07-699 1007 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
	        	
	        case 9:   	// Tangkak 
	        	printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Payamas                         06-978 1861 |\n");
	        	printf("| Klinik Kesihatan Sg Mati                         06-975 1054 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
	        	
	        case 10:   	// Mersing 
	        	printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Jemaluang                       07-792 1271 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;	
		}
	}
	
	else if (state == 2){
		switch (district){
			case 1:			// Kuala Muda
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bukit Selambau                     04-419 3312 |\n");
				printf("| Klinik Kesihatan Bakar Arang                        04-422 0294 |\n");
				printf("| Klinik Kesihatan Kota Kuala Muda                    04-437 4225 |\n");
				printf("| Klinik Kesihatan Sg Lalang                          04-459 4127 |\n");
				printf("| Klinik Kesihatan Merbok                             04-457 2214 |\n");
				printf("| Klinik Kesihatan Bandar Sungai Petani               04-421 3355 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
	
			case 2:			// Kota Setar
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bandar Alor Setar                  04-730 8353 |\n");
				printf("| Klinik Kesihatan Simpang Kuala                      04-772 0853 |\n");
				printf("| Klinik Kesihatan Simpang Empat                      04-980 7214 |\n");
				printf("| Klinik Kesihatan Kuala Kedah                        04-762 1526 |\n");
				printf("| Klinik Kesihatan Alor Janggus                       04-730 1985 |\n");
				printf("| Klinik Kesihatan Jalan Putra                        04-730 1985 |\n");
				printf("| Klinik Kesihatan Langgar                            04-787 6648 |\n");
				printf("| Klinik Kesihatan Pokok Sena                         04-782 1355 |\n");
				printf("| Klinik Kesihatan Kota Sarang Semut                  04-787 6648 |\n");
				printf("| Klinik Kesihatan Datuk Kumbar                       04-730 6319 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 3:			// Kulim
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Taman Selasih                      04-491 7377 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 4:			// Kubang Pasu
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Ayer Hitam                         04-794 2101 |\n");
				printf("| Klinik Kesihatan Changlun                           04-924 1277 |\n");
				printf("| Klinik Kesihatan Laka Temin                         04-922 2560 |\n");
				printf("| Klinik Kesihatan Napoh                              04-916 4944 |\n");
				printf("| Klinik Kesihatan Tunjang                            04-929 1524 |\n");
				printf("| Klinik Kesihatan Banai                              04-917 0375 |\n");
				printf("| Klinik Kesihatan Kodiang                            04-925 0178 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 5:			// Baling
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Malau                              04-406 1700 |\n");
				printf("| Klinik Kesihatan Kupang                             04-476 6355 |\n");
				printf("| Klinik Kesihatan Parit Panjang                      04-476 1246 |\n");
				printf("| Klinik Kesihatan Tawar                              04-476 6308 |\n");
				printf("| Klinik Kesihatan Kuala Ketil                        04-416 3355 |\n");
				printf("| Klinik Kesihatan Kampung Lalang                     04-472 1613 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 6:			// Pendang 
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Pendang                            04-759 6412 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 7:			// Langkawi
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Kuah                               04-966 3490 |\n");
				printf("| Klinik Kesihatan Padang Masirat                     04-955 1355 |\n");
				printf("| Klinik Kesihatan Ayer Hangat                        04-959 1959 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 8:			// Yan
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Guar Cempedak                      04-468 4435 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
				
			case 9:			// Sik
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Jeniang                            04-464 1200 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 10:		// Padang Terap
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Kuala Nerang	                      04-786 6355 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
				
			case 11:		// Pokok Sena
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Not Available	                                                  |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 12:		// Bandar Baharu
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bandar Baharu                      05-717 8232 |\n");
				printf("| Klinik Kesihatan Lubuk Buntar                       04-407 7320 |\n");
				printf("| Klinik Kesihatan Serdang                            04-407 7355 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
		}
	}
		
	else if (state == 3){
		switch (district){
			case 1:   		// Kota Bharu
	        	printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Kota Jembalt		               09-766 6733 |\n");
	        	printf("| Klinik Kesihatan Perol	                       09-712 3354 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
        
	    	case 2:    		// Pasir Mas
	        	printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Meranti                         09-797 5211 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
	        	
	        case 3:			// Tumpat
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Not Available	                                                  |\n");
				printf("-------------------------------------------------------------------\n");
				break;
	
	        case 4:    		// Bachok 
	        	printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Mahligai		                   09-783 4213 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
	        	
	        case 5:			// Tanah Merah
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Not Available	                                                  |\n");
				printf("-------------------------------------------------------------------\n");
				break;
	
	    	case 6:    		// Pasir Puteh
				printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Pasir Puteh		               09-786 9291 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
	        	
	        case 7:			// Kuala Krai 
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Not Available	                                                  |\n");
				printf("-------------------------------------------------------------------\n");
				break;
	
	        case 8:   		// Machang
	    		printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Labok		                   09-787 8533 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
					
	    	case 9:   		// Gua Musang 
				printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Gua Musang                      09-912 1286 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
				
			case 10:  		 // Jeli
				printf("\n\n----------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Jeli		                       09-944 0333 |\n");
	        	printf("----------------------------------------------------------------\n");
	        	break;
		}
	}
	
	else if (state == 4){
		switch (district){
			case 1:		// Melaka Tengah
				printf("\n\n----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Tengkera                        06-336 0173 |\n");
	        	printf("| Klinik Kesihatan Seri Tanjung                    06-351 1333 |\n");
	        	printf("| Klinik Kesihatan Ayer Keroh                      06-232 3330 |\n");
	        	printf("| Klinik Kesihatan Kuala Sg. Baru                  06-387 6333 |\n");
	        	printf("| Klinik Kesihatan Masjid Tanah                    06-384 2533 |\n");
				printf("----------------------------------------------------------------\n");
				break;
	
			case 2:		// Alor Gajah
				printf("\n\n----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Durian Tunggal                  06-553 1134 |\n");
				printf("| Klinik Kesihatan Rembia                          06-316 1076 |\n");
				printf("| Klinik Kesihatan Alor Gajah                      06-556 6235 |\n");
				printf("----------------------------------------------------------------\n");
				break;
			
			case 3:		// Jasin
				printf("\n\n----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Merlimau                        06-263 1533 |\n");
	        	printf("| Klinik Kesihatan Simpang Bekoh                   06-523 6033 |\n");
				printf("----------------------------------------------------------------\n");
				break;
		}
	}

	else if (state == 5){
		switch (district){
			case 1:		// Seremban
				printf("\n\n-----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Nilai                            06-850 4013 |\n");
	        	printf("| Klinik Kesihatan Senawang                         06-676 6000 |\n");
	        	printf("| Klinik Kesihatan Seremban                         06-767 9267 |\n");
				printf("-----------------------------------------------------------------\n");
				break;
			
			case 2:		// Jempol
				printf("\n\n-----------------------------------------------------------------\n");
				printf("| Not Available                                                 |\n");
				printf("-----------------------------------------------------------------\n");
				break;
			
			case 3:		// Port Dickson
				printf("\n\n-----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Lukut                            06-651 1958 |\n");
	        	printf("| Klinik Kesihatan Pasir panjang Jempol             06-458 1667 |\n");
	        	printf("| Klinik Kesihatan Bahau                            06-454 1234 |\n");
	        	printf("| Klinik Kesihatan Palong 4,5.6                     06-466 6433 |\n");
				printf("-----------------------------------------------------------------\n");
				break;
			
			case 4:		// Tampin
				printf("\n\n-----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Gemas                            07-948 2352 |\n");
				printf("| Klinik Kesihatan Gemencheh                        06-431 8304 |\n");
				printf("-----------------------------------------------------------------\n");
				break;
			
			case 5:		// Kuala Pilah
				printf("\n\n-----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Terachi                          06-488 7202 |\n");
				printf("| Klinik Kesihatan Juasseh                          06-498 1581 |\n");
				printf("-----------------------------------------------------------------\n");
				break;
			
			case 6:		// Rembau
				printf("\n\n-----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Rembau                           06-685 2010 |\n");
	        	printf("| Klinik Kesihatan Astana Raja                      06-438 2401 |\n");
				printf("-----------------------------------------------------------------\n");
				break;
			
			case 7:		// Jerebu
				printf("\n\n-----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Pertang                          06-494 1287 |\n");
	        	printf("| Klinik Kesihatan Simpang Durian                   06-491 4522 |\n");
	        	printf("| Klinik Kesihatan Titi                             06-611 1398 |\n");
				printf("-----------------------------------------------------------------\n");
				break;
		}
	}
		
	else if (state == 6){
		switch (district){
			case 1:		// Kuantan
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Balok		            09-583 4533 |\n");
	        	printf("| Klinik Kesihatan Beserah		            09-544 5633 |\n");
	        	printf("| Klinik Kesihatan Bandar		            09-513 5571 |\n");
	        	printf("| Klinik Kesihatan Indera Mahkota		    09-573 0373 |\n");
	        	printf("| Klinik Kesihatan Kurnia		            09-536 1333 |\n");
	        	printf("| Klinik Kesihatan Paya Besar		        09-549 8811 |\n");  	
	        	printf("| Klinik Kesihatan Permatang Badak		    09-536 4626 |\n");
	        	printf("| Klinik Kesihatan Jaya Gading		        09-573 6572 |\n");
	        	printf("| Klinik Kesihatan Gambang		            09-548 4611 |\n");
	        	printf("| Klinik Kesihatan Bkt Goh		            09-547 8355 |\n");
	        	printf("| Klinik Kesihatan Sg Lembing		        09-541 1598 |\n");
				printf("---------------------------------------------------------\n");
				break;
	
			case 2:		// Temerloh
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Temerloh		            09-296 1275 |\n");
	        	printf("| Klinik Kesihatan Tanjung Lalang		    09-296 1152 |\n");
	        	printf("| Klinik Kesihatan Bandar Mentakab		    09-296 1152 |\n");
	        	printf("| Klinik Kesihatan Kuala Krau		        09-286 1242 |\n");
	        	printf("| Klinik Kesihatan Sanggang		            09-284 6333 |\n");
	        	printf("| Klinik Kesihatan Kerdau		            09-284 7003 |\n");
	        	printf("| Klinik Kesihatan Lanchang		            09-280 3233 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 3:		// Bentong
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bentong	                09-222 0134 |\n");
	        	printf("| Klinik Kesihatan Karak	                09-231 1245 |\n");
	        	printf("| Klinik Kesihatan Mempaga	                09-237 7654 |\n");
	        	printf("| Klinik Kesihatan Simpang Pelangai	        09-245 0755 |\n");
	        	printf("| Klinik Kesihatan Chemomoi	                09-1299 744 |\n");
	        	printf("| Klinik Kesihatan Telemong	                09-239 9972 |\n");
	        	printf("| Klinik Kesihatan Lurah Bilut	            09-237 7333 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 4:		// Maran
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Maran	                09-477 1333 |\n");
	        	printf("| Klinik Kesihatan Pekan Tajau	            09-477 4780 |\n");
	        	printf("| Klinik Kesihatan Chenor	                09-299 5391 |\n");
	        	printf("| Klinik Kesihatan Pekan Awah	            09-298 6333 |\n");
	        	printf("| Klinik Kesihatan Jengka 2	                09-467 4320 |\n");
	        	printf("| Klinik Kesihatan Jengka 22	            09-486 4423 |\n");
	        	printf("| Klinik Kesihatan Bandar Jengka	        09-467 7198 |\n");
	        	printf("| Klinik Kesihatan Jengka 7	                09-467 1566 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 5:		// Rompin
				printf("\n\n-----------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Rompin	                        09-414 0333 |\n");
	        	printf("| Klinik Kesihatan Tanjung Gemok	                09-794 3516 |\n");
	        	printf("| Klinik Kesihatan Tekek	                        09-419 1880 |\n");
	        	printf("| Klinik Kesihatan Leban Chondong	                09-414 9237 |\n");
	        	printf("| Klinik Kesihatan Bukit Ibam	                    09-445 7298 |\n");
	        	printf("| Klinik Kesihatan Bandar Tun Abdul Razak	        09-445 7297 |\n");
	        	printf("| Klinik Kesihatan Perantau Damai	                09-443 1333 |\n");
	        	printf("| Klinik Kesihatan Chanis	                        09-447 1106 |\n");
	        	printf("| Klinik Kesihatan Perwira Jaya	                    09-437 1176 |\n");
				printf("-----------------------------------------------------------------\n");
				break;
			
			case 6:		// Pekan
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bandar Pekan             09-421 1710 |\n");
	        	printf("| Klinik Kesihatan Peramu Jaya              09-426 9609 |\n");
	        	printf("| Klinik Kesihatan Chini                    09-456 6333 |\n");
	        	printf("| Klinik Kesihatan Nenasi                   09-418 1233 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 7:		// Bera
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Padang Luas              09-255 2062 |\n");
	        	printf("| Klinik Kesihatan Bandar 32                09-246 1988 |\n");
	        	printf("| Klinik Kesihatan Purun                    09-248 1585 |\n");
	        	printf("| Klinik Kesihatan Triang                   09-255 5333 |\n");
	        	printf("| Klinik Kesihatan Kemayan                  09-240 9715 |\n");
	        	printf("| Klinik Kesihatan Bukit Mendi              09-245 0161 |\n");
	        	printf("| Klinik Kesihatan Tembangau                06-468 5730 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 8:		// Raub
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Dong		                09-365 8355 |\n");
	        	printf("| Klinik Kesihatan Jeruas		            09-365 7398 |\n");
	        	printf("| Klinik Kesihatan Tersang	                09-340 3086	|\n");
	        	printf("| Klinik Kesihatan Lembah Klau		        09-368 8333 |\n");
				printf("---------------------------------------------------------\n");
				break;
				
			case 9:		// Jerantut
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Jengka 8	                09-208 1554 |\n");
	        	printf("| Klinik Kesihatan Damak	                09-268 1425 |\n");
	        	printf("| Klinik Kesihatan Sg Tekam Utara	        09-481 1526 |\n");
	        	printf("| Klinik Kesihatan Bandar Jerantut	        09-266 2202 |\n");
	        	printf("| Klinik Kesihatan Kuala Tembeling	        09-308 6033 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 10:	// Lipis
				printf("\n\n------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Benta                       09-323 9211 |\n");
	        	printf("| Klinik Kesihatan Padang Tengku               09-329 1533 |\n");
	        	printf("| Klinik Kesihatan Bukit Betong                09-329 1212 |\n");
	        	printf("| Klinik Kesihatan Merapoh                     09-912 2377 |\n");
	        	printf("| Klinik Kesihatan Mela                        09-312 9424 |\n");
	        	printf("| Klinik Kesihatan Sungai Koyan                09-340 1533 |\n");
	        	printf("| Klinik Kesihatan Jerkoh                      09-312 9424 |\n");
	        	printf("| Klinik Kesihatan Ibu Anak(KKIA) Lipis        09-513 2055 |\n");
				printf("------------------------------------------------------------\n");
				break;
			
			case 11:	// Cameron Highlands
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Ringlet		            05-495 6581 |\n");
				printf("| Klinik Kesihatan Kg. Raja		            09-695 3853 |\n");
				printf("| Klinik Kesihatan Tanah Rata		        05-491 1257 |\n");
				printf("---------------------------------------------------------\n");
				break;
		}
	}
	
	else if (state == 7){
		switch (district){
			case 1:		// Timur Laut Pulau Pinang
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Jalan Perak		        04-281 8900 |\n");
				printf("---------------------------------------------------------\n");
				break;
		
			case 2:		// Seberang Perai Tengah
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Seberang Jaya		    04-390 0264 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 3:		// Seberang Perai Utara
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Sungai Dua		        04-642 2201 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 4:		// Barat Daya Pulau Pinang
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bayan Baru               04-642 5102 |\n");
				printf("---------------------------------------------------------\n");
				break;
				
			case 5:		// Seberang Perai Selatan
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bukit Panchor		    04-593 5892 |\n");
				printf("---------------------------------------------------------\n");
				break;
		}
	}

	else if (state == 8){
		switch (district){
			case 1:		// Kinta
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Jelapang	                05-526 3834 |\n");
				printf("| Klinik Kesihatan Greentown	            05-253 0801 |\n");
				printf("---------------------------------------------------------\n");
				break;
				
			case 2:		// Laut, Matang Dan Selama
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Simpang		            05-849 1466 |\n");
				printf("---------------------------------------------------------\n");
				break;
				
			case 3:		// Manjung
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Sitiawan Mualim		    05-691 4355 |\n");
				printf("| Klinik Kesihatan Tanjung Malim		    05-459 6333 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 4:		// Hilir Perak
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Teluk Intan              05-621 4020 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 5:		// Kerian
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bagan Serai              05-721 5355 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 6:		// Batang Padang
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Tap                      	-	    |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 7:		// Kuala Kangsar
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Padang Rengas            05-758 4355 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 8:		// Perak Tengah
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Seri Iskandar		    05-373 1903 |\n");
				printf("---------------------------------------------------------\n");
				break;
				
			case 9:		// Hulu Perak
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Lenggong	       	        05-767 7355 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 10:	// Kampar
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Kampar                   05-465 9197 |\n");
				printf("---------------------------------------------------------\n");
				break;
				
			case 11:	// Muallim
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Sitiawan Mualim		    05-691 4355 |\n");
				printf("---------------------------------------------------------\n");
				break;
				
			case 12:	// Bagan Datuk
				printf("\n\n---------------------------------------------------------\n");
				printf("| Not Available		                                    |\n");
				printf("---------------------------------------------------------\n");
				break;
		}
	}

	else if (state == 9){
		printf("\n\n---------------------------------------------------------\n");
    	printf("| Klinik Kesihatan Beseri                   04-938 1355 |\n");
		printf("| Klinik Kesihatan Kangar                   04-977 9043 |\n");
		printf("| Klinik Kesihatan Padang Besar             04-949 0333 |\n");
		printf("| Klinik Kesihatan Simpang Empat            04-762 1526 |\n");
		printf("---------------------------------------------------------\n");
	}

	else if (state == 10){
		switch (district){
			case 1:   // Kota Kinabalu
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Inanam                 088-421694 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 2:   // Tawau
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Merotai Besar	      089-902601 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 3:   // Sandakan
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Sandakan               089-225800 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 4:   // Lahad Datu
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Lahad Datu	          089-885110 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 5:   // Keningau
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Apin-Apin		      087-337371 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 6:   // Kinabatangan 
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Bukit Garam            089-562151 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 7:   // Semporna
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Semporna	              089-781695 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 8:   // Papar
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Kinarut                088-750331 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 9:   // Penampang
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Penampang  	          088-717978 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 10:   // Beluran
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Pejabat Kesihatan Kuala Sapi            089-552602 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 11:   // Tuaran
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Kiulu	              088-782830 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		
		    case 12:   // Ranau
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Kundasang              088-889722 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 13:   // Kota Belud
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Jawi-Jawi		      088-976001 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 14:  // Kudat
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Karakit		          088-671526 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 15:  // Kota Marudu
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Tandek                 088-661533 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 16:  // Beaufort
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Kilnik kesihatan Kota Klias		      087-881143 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 17:  // Kunak
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Daerah Kunak	          089-851733 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 18:  // Tenom
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Kemabong	              087-736896 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 19:  // Putatan
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Putatan		         088-765 704 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 20:  // Pitas
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Telaga		          088-638005 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 21:  // Tambunan
		        printf("\n\n------------------------------------------------------\n");
		        printf("| Klinik Kesihatan Sunsuron	              089-892002 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 22:  // Tongod
		        printf("\n\n------------------------------------------------------\n");
		        printf("Klinik Kesihatan Tongod	                  089-719004 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 23:  // Sipitang
		        printf("\n\n------------------------------------------------------\n");
		        printf("Klinik Kesihatan Meligan	              087-821066 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 24:  // Nabawan 
		        printf("\n\n------------------------------------------------------\n");
		        printf("Klinik Kesihatan Nabawan		          087-366199 |\n");
		        printf("------------------------------------------------------\n");
		        break;
		        
		    case 25:  // Kuala Penyu 
		        printf("\n\n------------------------------------------------------\n");
		        printf("Klinik Kesihatan Menumbok	              087-831066 |\n");
		        printf("------------------------------------------------------\n");
		        break;
	    }
	}
	
	else if (state == 11){
		switch (district){
			case 1:		// Kuching
				printf("\n\n---------------------------------------------------------\n");
				printf("| Kompleks Belia dan Sukan		            082-232 029 |\n");
				printf("---------------------------------------------------------\n");
				break;
		
			case 2:		// Miri
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Miri                 	085-412 322 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 3:		// Sibu
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Lanang                   084-210 433 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 4:		// Bintulu
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bintulu		            086-858 200 |\n");
	        	printf("| Klinik Kesihatan Tatau		            086-584 289 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 5:		// Serian
				printf("\n\n---------------------------------------------------------\n");
				printf("| Institut Latihan KKM Serian		         082-874089 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 6:		// Samarahan
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Kota Samarahan           082-671 285 |\n");
	        	printf("| Klinik Kesihatan Sebuyau                  083-467 126 |\n");
	       	 	printf("| Klinik Kesihatan Asajaya                  082-828 124 |\n");
	        	printf("| Klinik Kesihatan Sadong Jaya              082 821 084 |\n");
	        	printf("| Klinik Kesihatan Munggu Lallang           083-565 101 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 7:		// Sri Aman
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Sri Aman		            083-327 769 |\n");
	        	printf("| Klinik Kesihatan Lubok Antu	            083-584 105 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 8:		// Betong
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Mid Layar		             -      |\n");
	        	printf("| Klinik Kesihatan Debak	                083-464 570 |\n");
	        	printf("| Klinik Kesihatan Pusa	                    083-465 155 |\n");
	        	printf("| Klinik Kesihatan Beladin	                083-466 748 |\n");
	        	printf("| Klinik Kesihatan Roban	                083-427 244 |\n");
	        	printf("| Klinik Kesihatan Kabong	                083-411 211 |\n");
				printf("---------------------------------------------------------\n");
				break;
				
			case 9:		// Sarikei
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bintangor	                      084-693 333 |\n");
	        	printf("| Emergency & Trauma Depart. Hospital Sarikei	      084-653 333 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 10:	// Kapit
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Kapit       	            084-799 661 |\n");
	        	printf("| Klinik Kesihatan Song        	            084-777 634 |\n");
	        	printf("| Klinik Kesihatan Sg Asap                       -      |\n");
	        	printf("| Klinik Kesihatan Belaga        	        086-461 323 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 11:	// Limbang
				printf("\n\n---------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Kuala Lawas         	                085-284 871 |\n");
	        	printf("| Emergency & Trauma Depart. Hospital Limbang         	085-211 200 |\n");
				printf("---------------------------------------------------------------------\n");
				break;
			
			case 12:	// Mukah
				printf("\n\n---------------------------------------------------------------------\n");
				printf("| Emergency & Trauma Depart. Hospital Mukah             084-871 333 |\n");
				printf("---------------------------------------------------------------------\n");
				break;
		}
	}
	
	else if (state == 12){
		switch (district){
			case 1:		// Petaling
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Kelana Jaya		                 03-7804 5001 |\n");
				printf("| Klinik Kesihatan Taman Medan		                 03-7781 9001 |\n");
				printf("| Klinik Kesihatan Puchong		                     03-8051 2815 |\n");
				printf("| Klinik Kesihatan Seksyen 19 Shah Alam		         03-5541 3570 |\n");
				printf("| Klinik Kesihatan Seksyen 7 Shah Alam		         03-5518 6531 |\n");
				printf("| Klinik Kesihatan Seri Kembangan		             03-8945 5929 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
	
			case 2:		// Hulu Langat
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bandar Tun Hussein Onn            03-9081 3792 |\n");
	        	printf("| Klinik Kesihatan Semenyih                          03-8723 8355 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 3:		// Klang
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bandar Botanik		             03-3324 4260 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 4:		// Gombak
				printf("\n\n-------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Sg Buloh                          03-6140 1293 |\n");
	        	printf("| KK Selayang Baru                                   03-6187 8564 |\n");
	        	printf("| Klinik Kesihatan AU2                               03-4251 9005 |\n");
	        	printf("| Klinik Kesihatan Taman Ehsan                       03-6272 7471 |\n");
	        	printf("| Klinik Kesihatan Rawang                            03-6091 9055 |\n");
	        	printf("| Klinik Kesihatan Gombak Setia                      03-6177 0305 |\n");
	        	printf("| Klinik Kesihatan Kuang                             03-6037 1355 |\n");
	        	printf("| Klinik Kesihatan Batu Arang                        03-6035 2287 |\n");
	        	printf("| KK Hulu Kelang                                     03-4105 6640 |\n");
	        	printf("| Klinik Kesihatan Batu 8                            03-6188 9704 |\n");
				printf("-------------------------------------------------------------------\n");
				break;
			
			case 5:		// Kuala Langat
				printf("\n\n--------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Jenjarom		                      03-3191 3066 |\n");
	        	printf("| Klinik Kesihatan Teluk Datuk	                      03-3187 1117 |\n");
	        	printf("| Klinik Kesihatan Teluk Panglima Garang		      03-3122 7433 |\n");
	        	printf("| Klinik Kesihatan Sijangkang	                      03-3122 6686 |\n");
	        	printf("| Klinik Kesihatan Kebun Baru		                  03-3122 0943 |\n");
	        	printf("| Klinik Kesihatan Bandar	                          03-3120 1333 |\n");
	        	printf("| Klinik Kesihatan Tg. Sepat		                  03-3197 2044 |\n");
	        	printf("| Klinik Kesihatan Bukit Changgang	                  03-3149 1355 |\n");
				printf("--------------------------------------------------------------------\n");
				break;
			
			case 6:		// Sepang
				printf("\n\n--------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Salak    		                  03-8706 9001 |\n");
	        	printf("| Klinik Kesihatan Sg Pelek    		                  03-3141 1242 |\n");
	        	printf("| Klinik Kesihatan Dengkil   		                  03-8768 6355 |\n");
				printf("--------------------------------------------------------------------\n");
				break;
			
			case 7:		// Kuala Selangor
				printf("\n\n--------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bestari Jaya		                  03-3271 9151 |\n");
	        	printf("| Klinik Kesihatan Kuala selangor		              03-3289 1142 |\n");
	        	printf("| Klinik Kesihatan Jeram		                      03-3264 7075 |\n");
	        	printf("| Klinik Kesihatan Ijok		                          03-3279 1167 |\n");
				printf("--------------------------------------------------------------------\n");
				break;
			
			case 8:		// Hulu Selangor
				printf("\n\n--------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bandar Tun Hussein Onn             03-9081 3792 |\n");
	        	printf("| Klinik Kesihatan Semenyih                           03-8723 8355 |\n");
	        	printf("| Klinik Kesihatan Bangi                              03-8925 8707 |\n");
	        	printf("| Klinik Kesihatan Batu 14                            03-9021 1414 |\n");
				printf("--------------------------------------------------------------------\n");
				break;
				
			case 9:		// Sabak Bernam
				printf("\n\n--------------------------------------------------------------------\n");
				printf("| Klinik Kesihatan Simpang Lima                   	  03-3224 2823 |\n");
				printf("--------------------------------------------------------------------\n");
				break;
		}
	}
	
	else if (state == 13){
		switch (district){
			case 1:		// Kuala Terengganu
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Manir                    09-615 1447 |\n");
				printf("---------------------------------------------------------\n");
				break;
		
			case 2:		// Kemaman
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Batu 2 1/2               09-858 1540 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 3:		// Dungun
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Ketengah Jaya		    09-820 0233 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 4:		// Besut
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Padang Luas              09-255 2062 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 5:		// Marang
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Bukit Payong		        09-619 1333 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 6:		// Hulu Terengganu
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Kuala Berang		        09-681 1597 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 7:		// Setiu
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Rahmat                   09-609 7033 |\n");
				printf("---------------------------------------------------------\n");
				break;
			
			case 8:		// Kuala Nerus
				printf("\n\n---------------------------------------------------------\n");
				printf("| Klinik Kesihatan Batu Rakit               09-669 3331 |\n");
				printf("---------------------------------------------------------\n");
				break;
		}
	}
	
	else if (state == 14){
		switch (district){
			case 1:    // Kepong
	        	printf("\n\n------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Jinjang	     	          03-6258 3355 |\n");
	        	printf("------------------------------------------------------------\n");
	        	break;
	        	
	        case 2:	  // Lembah Pantai
	        	printf("\n\n------------------------------------------------------------\n");
	        	printf("| Not Available	     	                                   |\n");
	        	printf("------------------------------------------------------------\n");
	        	break;
	
	        case 3:   // Titiwangsa
				printf("\n\n------------------------------------------------------------\n");
	        	printf("| Klinik Kesihatan Kuala Lumpur               03-2618 3200 |\n");
	        	printf("----------------------------------------------------------- \n");
	        	break;
					
	    	case 4:   // Cheras
				printf("\n\n------------------------------------------------------------\n");
	        	printf("| Pejabat Kesihatan - drive through	          03-7884 0400 |\n");
	        	printf("------------------------------------------------------------\n");
	        	break;    
		}
	}
	
	else if (state == 15){
		printf("-----------------------------------------------------------|\n");
    	printf("| Klinik Kesihatan Labuan                       087-596888 |\n");
		printf("-----------------------------------------------------------|\n");
	}
	
	else if (state == 16){
		printf("\n\n-----------------------------------------------------------------------------\n");
		printf("| Klinik Kesihatan Putrajaya Presint 9                         03-8888 3057 |\n");
		printf("| Pejabat Kesihatan Putrajaya - drive through                  03-8885 0400 |\n");
		printf("-----------------------------------------------------------------------------\n");	
	}
	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
					    scanf("%d",&main_exit);
					    system("cls");
					    if (main_exit==1)
					       	 menu();	
					    else
					         close();		
}

void faq() //FAQs
{
	printf("\n\n\n\n\t\t\tLOADING FAQs");
    	for(i=0;i<=6;i++)
    	{
            fordelay(100000000);
            printf(".");
   		}
    system("cls");
    printf("\t\t\t\t\xB2\xB2\xB2\xB2\ FAQ MySejahtera \xB2\xB2\xB2\xB2\n\n");
    printf("1. What is MySejahtera?\n");
    printf(" > MySejahtera is an application developed by the Government of Malaysia to assist in managing\n");
	printf("   the COVID-19 outbreaks in the country.\n"); 
	printf(" > It allows users to perform health self-assessment on themselves and their families.\n"); 
	printf(" > The users can also monitor their health progress throughout the COVID-19 outbreak.\n"); 
	printf(" > In addition, MySejahtera enables Ministry of Health (MOH) to monitor users' health condition\n"); 
	printf("   and take immediate actions in providing the treatments required.\n\n");
    printf("MySejahtera application is developed to:\n\n");
    printf(" - Assists the Government in managing and mitigating the COVID-19 outbreak\n");
    printf(" - Helps users in monitoring their health throughout the COVID-19 outbreak\n");
    printf(" - Assists users in getting treatment if they are infected with COVID-19\n");
    printf(" - Locates nearest hospitals and clinics for COVID-19 screening and treatment\n\n");

    printf("2. Who developed MySejahtera?\n\n");
    printf(" > MySejahtera is developed through a strategic cooperation between the National Security Council (NSC), \n");
	printf("   the Ministry of Health (MOH), the Malaysian Administrative Modernisation and Management Planning Unit (MAMPU) \n");
	printf("   and Malaysian Communications and Multimedia Commission (MCMC) and Ministry of Science, \n");
	printf("   Technology and Innovation (MOSTI).\n\n");

	printf("3. Who can use MySejahtera?\n\n");
	printf(" > MySejahtera is used by: \n");
	printf("	- Malaysians and residents of Malaysia\n");
	printf("	- System administrator in MOH\n\n");
	
    printf("4. What are the laws related to the implementation of MySejahtera?\n\n");
    printf(" > MySejahtera was developed to support the implementation of the Prevention and \n");
	printf("   Control of Infectious Diseases Act 1988 [Act 342].\n\n");
    printf(" > Providing false information is an offence under Section 22 of the Prevention and Control of \n");
	printf("   Infectious Diseases Act 1988 [Act 342] and Section 233 of the Communication and\n"); 
	printf("   Multimedia Act 1998 [Act 588.]\n\n");

    printf("5. How will the information that I submit throught the application help the Governmentin managing \n");
	printf("   the outbreak of Covid-19 in Malaysia?\n\n");
    printf(" > Essentially, your information will be used by the MOH to help them plan their resources and actions \n");
	printf("   that they need to take efficiently. So please be honest when you submit your information. \n");
	printf("   Honesty will help flatten the curve.\n\n");

    printf("6. What is the minimun mobile device's requirement to use MySejahtera?\n\n");
    printf("  i. Smartphones running Android 4.4 and above or iOS 12 and above.\n");
    printf(" ii. Internet connection\n");
    printf("iii. Able to receive SMS for the system to send One-Time-Pin(OTP) for the verification process.\n\n");

    printf("7. Where can I download MySejahtera app?\n\n");
    printf(" > MySejahtera in available in Galeri Aplikasi Mudah Alih Kerajaan Malaysia (GAMMA), \n");
	printf("   Apple App Store, Google Play Store and Huawei AppGallery.\n\n");
    
    printf("8. Do I have to pay to download MySejahtera application?\n\n");
    printf(" > No, MySejahterais FREE to use.\n\n");

    printf("9. How do I register in MySejahtera?\n\n");
    printf(" > To register, you need to follow these steps: \n");
    printf("Step 1: Download and install MySejahtera from the Gallery of Malaysian Government Mobile Applications (GAMMA), \n");
	printf("        Apple AppStore, Google Play Store or Huawei AppGallery\n");
    printf("Step 2: Click on 'Register Here' to register a new account\n");
    printf("Step 3: Enter your mobile phone number and click 'Register' or click on the link \n"); 
	printf("        'I would like to use Email to Register' \n");
	printf("        (if you want to register using email address)\n");
    printf("Step 4: You will receive an OTP via SMS from 63839 (if you register using phone number)\n"); 
	printf("        or confirmation link through your email (if you register using email address)\n");
    printf("Step 5: Enter the OTP and click 'Send' (if you register using phone number) or click on the confirmation link sent\n"); 
	printf("        to your email (if you register using email address)\n");
    printf("Step 6: Fill in your registration details and click 'Confirm'\n");
    printf("Step 7: You will receive a 'Successful Registration' message. Click 'Close' at the bottom of the screen to return\n"); 
	printf("        to the sign-in screen\n");
    printf("Step 8: Enter your User ID (phone number or email address) and your password and click 'Sign in'.\n");
    printf("Step 9: Congratulation! You may start using the app.\n\n");
    printf("10. Can I register my family members or other individuals living with me ?\n\n");
    printf(" > Yes, you can register for those who do not have a phone number or access to smartphones by using the\n"); 
	printf("   'Manage Dependents' function in this app.\n");
	printf("   This application will also help you to monitor their health\n\n");

    printf("11. What is user classification in MySejahtera?\n\n");
    printf("    > Once you have compiled the self-health assessment, your status will be classified as one of the following:                              \n\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|     # Classification                  |                                    Description                                                      |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|     1 Low Risk                        |- Individuals with low risk of COVID-19 infection.                                                   |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|     2 Casual Contact                  |- Individuals who were likely exposed to another person infected with COVID-19.                      |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|     3 Close Contact                   | Individuals who have been exposed to other individuals infected with COVID-19. This includes:       |\n");
    printf("|                                       |- Health care associated exposure, including providing direct care for COVID19 patients              |\n"); 
    printf("|                                       |  without using appropriate PPE, working with health care workers infected with COVID-19,            |\n");
    printf("|                                       |  visiting patients or staying in the same close environment of a COVID-19 patient.                  |\n");
    printf("|                                       |- Working together in close proximity or sharing the same classroom environment with a with COVID-19 |\n");   
    printf("|                                       |  patient                                                                                            |\n");
    printf("|                                       |- Living in the same household as a COVID-19 patient                                                 |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|     4 Person Under Surveillance (PUS) |- Individuals who are at risk of being infected with COVID-19. For example individuals with a history|\n"); 
    printf("|                                       |  of traveling abroad within the last 14 days.                                                       |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|     5 Suspected Case                  |- Individuals who are at risk of being infected with COVID-19, for example, individuals with a       |\n");
    printf("|                                       |  history of traveling abroad or have attended mass gatherings within 14 days before the onset of    |\n");
    printf("|                                       |  symptoms                                                                                           |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|     6 Confirmed Case                  |- Individuals tested positive for COVID-19                                                           |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    printf("12. Where can I get help for technical issues?\n\n");
    printf(" > User can submit complaints through the 'MySejahtera Helpdesk' function within the application.\n\n");

    printf("13. Is my personal information shared in this application secure?\n\n");
    printf(" > MySejahtera is owned and operated by the Government of Malaysia. It is administrated by MOH and assisted by\n"); 
	printf("   NSC and MAMPU.\n");
	printf(" > The Government assures that your personal information will only be used for the purpose of managing and mitigating\n"); 
	printf("   COVID-19 outbreak. It will not be shared to any other party.\n\n");
    printf("14. If I am identified as a COVID-19 patient, will my identity be protected?\n\n");
    printf(" > YES, the information of all COVID-19 patients is protected under the confidentiality of medical records.\n\n");
	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
		scanf("%d",&main_exit);
		system("cls");
		if (main_exit==1)
		   	 menu();	
		else
		     close();
    return;
}

void tambahan_tanggungan() //Tambah Tanggungan
{
    char choice;
    FILE *ptr;
    ptr=fopen("record.dat","a+");
    ic_no:
    printf("\n\n\n\n\t\t\tLOADING TAMBAH TANGGUNGAN");
    	for(i=0;i<=6;i++)
    	{
            fordelay(100000000);
            printf(".");
   		}
    system("cls");
    printf("\t\t\t\t\xB2\xB2\xB2\xB2\ TAMBAH TANGGUNGAN \xB2\xB2\xB2\xB2");
    printf("\n\nDo you wanna add dependent?\n");
    printf("Enter 'Y'for YES, 'N' for NO\n\n");
    scanf("%s", &choice);

    while(choice=='Y')
    {	
    	system("cls");
	    printf("Enter your dependent's details.\n");
	    printf("\nEnter NRIC/ Passport No(XXXXXX-XX-XXXX): ");
	    scanf("%d-%d-%d", &check.ic_no1,&check.ic_no2,&check.ic_no3);
	    while(fscanf(ptr,"%d-%d-%d %[^\n]s %d/%d/%d %d %d %s %s %d %lf",&add.ic_no1,&add.ic_no2,&add.ic_no3,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.relation,&add.age,add.gender,add.address,&add.postcode,&add.phone)!=EOF)
    	{
	        if (check.ic_no1==add.ic_no1 && check.ic_no2==add.ic_no2 && check.ic_no3==add.ic_no3)
	            {
					printf("Account already existed!");
		            fordelay(1000000000);
		                goto ic_no;
	            }
    	}
    	add.ic_no1=check.ic_no1;
    	add.ic_no2=check.ic_no2;
    	add.ic_no3=check.ic_no3;
	    printf("Full name: ");
	    scanf(" %[^\n]s", add.name);
	    printf("--------------------------------------------------------------------------------------\n");
	    printf("| NO. | 								Relationship                                 |\n");
	    printf("|------------------------------------------------------------------------------------|\n");
	    printf("|  1. | Spouse                   |  2. | Child              |  3. | Siblings         |\n");
	    printf("|  4. | Parents/Parents-in-law   |  5. | Grandparents       |  6. | Guardian         |\n");
	    printf("--------------------------------------------------------------------------------------\n");
	    printf("Choose relation: ");
	    scanf("%d", &add.relation);
	    printf("\nEnter his/ her age: ");
	    scanf("%d", &add.age);
	    printf("\nWhat is your gender?\n");
		printf("Enter 'M' for MALE or 'F' for FEMALE.\n");
	    scanf("%d", &add.gender);
		    while (add.gender != 'M' && add.gender != 'F'){
		    printf("Error! Please enter again!\n");
		    printf("\nChoose your gender: \n");
		    printf("Enter 'M' for MALE or 'F' for FEMALE.\n");
	    	scanf("%s", &add.gender);
	   		}
	    printf("\n");
	    printf("\nEnter FULL address: ");
	    scanf(" %[^\n]s", add.address);
	    printf("Account successfully registered!\n");
	    printf("\nDo you wanna add another dependent?");
	    printf("\nEnter 'Y'for YES, 'N' for NO\n");
	    scanf(" %s", choice);
	    	while(choice != 'Y' && choice != 'N'){
	    		printf("Error! Please re-enter your choice!\n");
	    		printf("\nDo you wanna add another dependent?");
	   			printf("\nEnter 'Y'for YES, 'N' for NO\n");
	   			scanf(" %s", choice);
			}
	}
		if (choice == 'N'){
	        fprintf(ptr,"%d-%d-%d %s %d/%d/%d %d %d %s %s %d %lf \n",add.ic_no1,add.ic_no2,add.ic_no3,add.name,add.dob.day,add.dob.month,add.dob.year,add.relation,add.age,add.gender,add.address,add.postcode,add.phone);
		    fclose(ptr);
		    printf("\nAccount created successfully!");
		    add_invalid:
		    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
		    scanf("%d",&main_exit);
		    system("cls");
		    if (main_exit==1)
		        menu();
		    else if(main_exit==0){
		    	close();
				}   
		    else
		        {
		            printf("\nInvalid!\a");
		            goto add_invalid;
		        }
	}
}

void account_settings() //Account settings
{
		int choice;
		printf("\n\n\n\n\t\t\tLOADING ACCOUNT SETTINGS");
    	for(i=0;i<=6;i++)
    	{
            fordelay(100000000);
            printf(".");
   		}
   		system("cls");
		printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Account Settings \xB2\xB2\xB2\xB2");
		printf("\n\n\t\t1. Search registered account(s)\n");
		printf("\t\t2. Update your information\n");
		printf("\t\t3. Remove existing account\n");
		printf("\t\t4. View registered account(s)\n");
		printf("\t\t5. Back to Main Menu\n");
		printf("\n\n\n\n\t\t Enter your choice: ");
		scanf("%d", &choice);
		system("cls");
		switch (choice){
			case 1:
				search_acc();
				break;
			case 2:
				edit_acc();
				break;
			case 3:
				remove_acc();
				break;
			case 4:
				view_list();
				break;
			case 5:
				menu();
				break;
	}
	while (choice < 1 || choice > 5){
	    printf("Error! Please re-enter your choice: ");
	    scanf("%d",&choice);
	    system("cls");
	}
}

void additional_resources() //Additional resources
{
		int resource, COVID_19_test;
			printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Additional Resources \xB2\xB2\xB2\xB2");
			printf("\n\n\t\t1. Smoking & COVID 19\n");
			printf("\t\t2. Get COVID-19 Test At Home(Self Paid)\n");
			printf("\n\n\n\n\t\t Enter your choice: ");
			scanf("%d",&resource);
			if (resource == 1)
			{
				system("explorer https://www.jomquit.com/");
				printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Smoking & COVID 19 \xB2\xB2\xB2\xB2");
				printf("\n\n\t\tWe will now direct you to https://www.jomquit.com/");
				for(i=0;i<=6;i++)
				        	{
					            fordelay(100000000);
					            printf(".");
				       		}
				system("cls");
				printf("\nEnter 1 to go to the main menu and 0 to exit:");
				    scanf("%d",&main_exit);
				    system("cls");
				    if (main_exit==1)
				       	 menu();	
				    else{
				         close();
				     }
			}
			if (resource == 2)
			{
				printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Get COVID-19 Test At Home \xB2\xB2\xB2\xB2");
				printf("\n\n\t\t1. Qualitads Medical Group\n");
				printf("\t\t2. Pantai Premier Pathology\n");
				printf("\t\t3. Bookdoc\n");
				printf("\t\t4. Lablink Sdn Bhd\n");
				printf("\t\t5. Sunway Medical Center\n");
				printf("\t\t6. Back to main menu\n");
				printf("\n\n\n\n\t\tPlease enter your choice: ");
				scanf("%d",&COVID_19_test);
				system("cls");
				switch (COVID_19_test)
				{
					case 1:
						system("explorer https://qualitas.com.my");
						printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Qualitads Medical Group \xB2\xB2\xB2\xB2");
						printf("\n\n\t\tWe will now direct you to https://qualitas.com.my");
						for(i=0;i<=6;i++)
				        	{
					            fordelay(100000000);
					            printf(".");
				       		}
				       	system("cls");
				       	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
					    scanf("%d",&main_exit);
					    system("cls");
					    if (main_exit==1)
					       	 menu();	
					    else{
					         close();
					     }
						break;
					case 2:
						system("explorer https://www.premierpathology.com.my");	
						printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Pantai Premier Pathology \xB2\xB2\xB2\xB2");
						printf("\n\n\t\tWe will now direct you to https://www.premierpathology.com.my");
						for(i=0;i<=6;i++)
				        	{
					            fordelay(100000000);
					            printf(".");
				       		}
				       	system("cls");
				       	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
					    scanf("%d",&main_exit);
					    system("cls");
					    if (main_exit==1)
					       	 menu();	
					    else{
					         close();
					     }
						break;
					case 3:
						system("explorer https://www.bookdoc.com");
						printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Bookdoc \xB2\xB2\xB2\xB2");
						printf("\n\n\t\tWe will now direct you to https://www.bookdoc.com");
						for(i=0;i<=6;i++)
				        	{
					            fordelay(100000000);
					            printf(".");
				       		}
				       	system("cls");
				       	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
					    scanf("%d",&main_exit);
					    system("cls");
					    if (main_exit==1)
					       	 menu();	
					    else{
					         close();
					     }
						break;
					case 4:
						system("explorer https://www.kpjlablink.com");
						printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Lablink Sdn Bhd \xB2\xB2\xB2\xB2");
						printf("\n\n\t\tWe will now direct you to https://www.kpjlablink.com");
						for(i=0;i<=6;i++)
				        	{
					            fordelay(100000000);
					            printf(".");
				       		}
				       	system("cls");
				       	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
					    scanf("%d",&main_exit);
					    system("cls");
					    if (main_exit==1)
					       	 menu();	
					    else{
					         close();
					     }
						break;
					case 5:
						system("explorer https://www.sunmedvelocity.com.my");
						printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Sunway Medical Center \xB2\xB2\xB2\xB2");
						printf("\n\n\t\tWe will now direct you to https://www.sunmedvelocity.com.my");
						for(i=0;i<=6;i++)
				        	{
					            fordelay(100000000);
					            printf(".");
				       		}
				       	system("cls");
				       	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
					    scanf("%d",&main_exit);
					    system("cls");
					    if (main_exit==1)
					       	 menu();	
					    else{
					         close();
					     }
						break;
					case 6:
						menu();
						break;
				}
			}
			while (COVID_19_test < 1 || COVID_19_test > 6)
			{
			    printf("Error! Please re-enter your choice: ");
			    scanf("%d",&COVID_19_test);
			    system("cls");
			}
}

void sop() //Standard Operating Procedures(SOP)
{
		system("explorer https://www.mkn.gov.my/web/ms/sop-pkp-pemulihan/");
		printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Standard Operating Procedure (SOP) \xB2\xB2\xB2\xB2");
		printf("\n\n\t\tWe will now direct you to https://www.mkn.gov.my/web/ms/sop-pkp-pemulihan/");
		for(i=0;i<=6;i++)
		        	{
			            fordelay(100000000);
			            printf(".");
		       		}
				printf("\nEnter 1 to go to the main menu and 0 to exit: ");
			    scanf("%d",&main_exit);
			    system("cls");
			    if (main_exit==1)
			       	 menu();	
			    else{
			    		close();
					}
}

void dir_helpdesklink() //Direct Link Helpdesk
{

		system("explorer https://www.mysejahtera.malaysia.gov.my/help_en/");
		printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Helpdesk \xB2\xB2\xB2\xB2");
		printf("\n\n\t\tWe will now direct you to https://www.mkn.gov.my/web/ms/sop-pkp-pemulihan/");
		for(i=0;i<=6;i++)
		        	{
			            fordelay(100000000);
			            printf(".");
		       		}
				printf("\nEnter 1 to go to the main menu and 0 to exit: \n");
			    scanf("%d",&main_exit);
			    system("cls");
			    if (main_exit==1)
			       	 menu();	
			    else{
			    		close();
					}
}

void digital_healthcare() //Virtual Health Assistant
{
	int healthcare,booking;
		printf("\n\n\n\n\t\t\tLOADING DIGITAL HEALTHCARE");
    	for(i=0;i<=6;i++)
    	{
            fordelay(100000000);
            printf(".");
   		}
   		system("cls");
		printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Digital Healthcare \xB2\xB2\xB2\xB2");
		printf("\n\n\t\t1. Virtual Health Advisory\n");
		printf("\t\t2. Clinic Appointment Booking\n");
		printf("\t\t3. Back to Main Menu\n");
		printf("\n\n\n\n\t\t Enter your choice: ");
		scanf("%d",&healthcare);
		system("cls");
		
		if (healthcare == 1){
			system("explorer https://www.doc2us.com/covid-19-advisory");
			printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Virtual Health Advisory \xB2\xB2\xB2\xB2");
			printf("\n\n\t\tWe will now direct you to https://www.doc2us.com/covid-19-advisory");
				for(i=0;i<=6;i++)
				        	{
					            fordelay(100000000);
					            printf(".");
				       		}
				system("cls");
				printf("\nEnter 1 to go to the main menu and 0 to exit: ");
				    scanf("%d",&main_exit);
				    system("cls");
				    if (main_exit==1)
				       	 menu();	
				    else{
				         close();
				     }
			}
		
		if (healthcare == 2){
			printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Clinic Appointment Booking \xB2\xB2\xB2\xB2");
			printf("\n\n\t\t1. QueueMed\n");
			printf("\t\t2. Encoremed\n");
			printf("\t\t3. Bookdoc\n");
			printf("\t\t4. Back to Digital Healthcare\n");
			printf("\n\n\n\n\t\t Enter your choice: ");
			scanf("%d",&booking);
			system("cls");
				switch (booking)
				{
					case 1:
						system("explorer https://qmed.asia/booking");
						printf("\t\t\t\t\xB2\xB2\xB2\xB2\ QueueMed \xB2\xB2\xB2\xB2");
						printf("\n\n\t\tWe will now direct you to https://qmed.asia/booking");
							for(i=0;i<=6;i++)
							        	{
								            fordelay(100000000);
								            printf(".");
							       		}
							system("cls");
							printf("\nEnter 1 to go to the main menu and 0 to exit: ");
							    scanf("%d",&main_exit);
							    system("cls");
							    if (main_exit==1)
							       	 menu();	
							    else{
							         close();
							     }
						break;
					case 2:
						system("explorer https://kkm.encoremed.io/#home/institutes");	
						printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Encoremed \xB2\xB2\xB2\xB2");
						printf("\n\n\t\tWe will now direct you to https://kkm.encoremed.io/#home/institutes");
							for(i=0;i<=6;i++)
							        	{
								            fordelay(100000000);
								            printf(".");
							       		}
							system("cls");
							printf("\nEnter 1 to go to the main menu and 0 to exit: ");
							    scanf("%d",&main_exit);
							    system("cls");
							    if (main_exit==1)
							       	 menu();	
							    else{
							         close();
							     }
						break;
					case 3:
						system("explorer https://www.bookdoc.com/covid19/kk-clinics");
						printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Bookdoc \xB2\xB2\xB2\xB2");
						printf("\n\n\t\tWe will now direct you to https://www.bookdoc.com/covid19/kk-clinics");
							for(i=0;i<=6;i++)
							        	{
								            fordelay(100000000);
								            printf(".");
							       		}
							system("cls");
							printf("\nEnter 1 to go to the main menu and 0 to exit: ");
							    scanf("%d",&main_exit);
							    system("cls");
							    if (main_exit==1)
							       	 menu();	
							    else{
							         close();
							     }
						break;
					case 4:
						digital_healthcare();
				}
			}
			if (healthcare == 3){
				menu();
			}
}

void others() //More features
{
		int choice;
		printf("\n\n\n\n\t\t\tLOADING MORE");
        	for(i=0;i<=6;i++)
        	{
	            fordelay(100000000);
	            printf(".");
       		}
       		system("cls");
		printf("\t\t\t\t\xB2\xB2\xB2\xB2\ MORE \xB2\xB2\xB2\xB2\n\n");
		printf("---------------------------------------------------\n");
  		printf("|  No |Details                                    |\n");
  		printf("|-----|-------------------------------------------|\n");
  		printf("|  1. |MyTrace                                    |\n");
  		printf("|  2. |Behavioural Risk                           |\n");
  		printf("|  3. |Additional Resources                       |\n");
  		printf("|  4. |Standard Operating Procedure (SOP)         |\n");
  		printf("|  5. |Helpdesk                                   |\n");
  		printf("|  6. |Back to Main Menu                          |\n");
  		printf("---------------------------------------------------\n\n");
  		
  		printf("Choose the details that you want to proceed with: ");
  		scanf("%d",&choice);
  		
  		while (choice > 7 || choice < 1)
		{
	  		printf("Error! Please reenter your choice:");
	  		scanf("%d",&choice);
		}
		system("cls");
		switch (choice){
			case 1:
				system("explorer https://play.google.com/store/apps/details?id=my.gov.onegovappstore.mytrace");
				printf("\t\t\t\t\xB2\xB2\xB2\xB2\ MyTrace \xB2\xB2\xB2\xB2");
				printf("\n\n\t\tWe will now direct you to https://play.google.com/store/apps/details?id=my.gov.onegovappstore.mytrace");
				for(i=0;i<=6;i++)
		        	{
			            fordelay(100000000);
			            printf(".");
		       		}
				printf("\nEnter 1 to go to the main menu and 0 to exit: ");
			    scanf("%d",&main_exit);
			    system("cls");
			    if (main_exit==1)
			       	 menu();	
			    else{
			    		close();
					}
				break;
			case 2:
				system("explorer https://myrisk.nih.gov.my");
				printf("\t\t\t\t\xB2\xB2\xB2\xB2\ Behavioural Risk \xB2\xB2\xB2\xB2");
				printf("\n\n\t\tWe will now direct you to https://myrisk.nih.gov.my");
				for(i=0;i<=6;i++)
		        	{
			            fordelay(100000000);
			            printf(".");
		       		}
				printf("\nEnter 1 to go to the main menu and 0 to exit: ");
				    scanf("%d",&main_exit);
				    system("cls");
				    if (main_exit==1)
				       	 menu();	
				    else{
				    	close();
					}
				break;
			case 3:
				additional_resources();
				break;
			case 4:
				sop();
				break;
			case 5:
				dir_helpdesklink();
				break;
			case 6:
				menu();
				break;
		}

}

void close() //End Program
{
	printf("\n\n\n\nThank you for using our App!");
}

void menu(void) //menu function
{   
	int choice, choose;
		display_main:
	    system("cls");
	    system("color 9");
	    printf("\t\t\t\t\xB2\xB2\xB2\xB2\ MYSEJAHTERA APP \xB2\xB2\xB2\xB2");
	    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    printf("\n\n\t\t1. Check-in                    Untuk mengemas kini lokasi anda\n\n\t\t2. Nombor Hotline              Membolehkan pengguna mendali terus \n\t\t                               ke hotline COVID-19\n\n\t\t3. Virtual Health Advisory     Membolehkan pengguna ke laman 'Doctor-on-Call'\n\n\t\t");
		printf("4. Ujian COVID-19 di rumah     Memaklumkan pengguna fasiliti kesihatan swasta \n\t\t                               yang menawarkan ujian COVID-19(berbayar)\n\n\t\t5. FAQs                        Membawa anda ke soalan yang sering ditanya \n\t\t                               berhubung COVID-19 dan aplikasi ini\n\n\t\t");
		printf("6. Tambah Tanggungan           Membenarkan anda menambah dan melaksanakan \n\t\t                               penilaian kendiri kepada tanggungan mereka\n\n\t\t7. Account Settings\t       Settings for registered accounts\n\n\t\t");
		printf("8. More\t\t\t       Extra Features\n\n\t\t9. Exit\t\t\t       Exit the program\n\n\n\n\n\t\t Enter your choice: ");
	    scanf("%d",&choice);
	    system("cls");
	    switch (choice)
		{
	    	case 1:
	    		otheroption = true;
	    		check_in();
	    		state_district();
				zone_cases();
				goto display_main;
	    		break;
	    	seriousness:
	    	case 2:
	    		choose = hotline_choice(choose);
				    if (choose == 1)
					    {
					        hotline_major();
					    }
				    if (choose == 2)
					    {
							Clinic_Hotline();
							Hotline();
					    }
				    if (choose == 0)
						{
					    	goto display_main;	
						}
					break;
	    	case 3:
	    		digital_healthcare();
	    		break;
	    	case 4:
	    		if (otheroption == true){
					self_test();
					if(choice1 == 'Y' && choice2 == 'Y' && choice3 == 'Y' && choice4 == 'Y' && choice5 == 'Y')
					{
						printf("Please go to the nearest hospital for a check-up!\n");
						goto seriousness;
					}
					else if(choice1 == 'N' || choice2 == 'N' || choice3 == 'N' || choice4 == 'N' || choice5 == 'N')
					{
						printf("\nEnter 1 to go to the main menu and 0 to exit: ");
					    scanf("%d",&main_exit);
					    system("cls");
					    if (main_exit==1)
					       	 menu();	
					    else
					         close();
					}
				}
				else{
					printf("Please check-in first!\n\n");
					printf("\nEnter 1 to go to the main menu and 0 to exit: ");
				    scanf("%d",&main_exit);
				    system("cls");
				    if (main_exit==1)
				       	 menu();	
				    else
				         close();
				    }
				break;
	    	case 5:
	    		faq();
	    		break;
			case 6:
				if (otheroption == true)
				{
					tambahan_tanggungan();
				}
				else{
					printf("Please check-in first!\n\n");
					printf("\nEnter 1 to go to the main menu and 0 to exit: ");
				    scanf("%d",&main_exit);
				    system("cls");
				    if (main_exit==1)
				       	 menu();	
				    else
				         close();
				}
				break;
			case 7:
				account_settings();
				break;
			case 8:
				others();
				break;	
			case 9:
				close();
				break;
	}		
	    		
}

int main() //main function
{
	char new_choice;
	system("color 9");
	{
        
		printf("\n\n\n\n\t\t\tPowered by 91-DIVOC\n\t\t\tLOADING");
        for(i=0;i<=6;i++)
        	{
	            fordelay(100000000);
	            printf(".");
       		}

        system("cls");
        repeat:
		printf("\n\nAre you a new user?\n");
		printf("Enter 'Y' for YES, 'N' for NO.\n\n");
		scanf("%s", &new_choice);
		system("cls");
		if(new_choice == 'Y')
			{
				new_acc();
			}
		else if(new_choice == 'N')
			{
				printf("\n\n\n\n\t\t\tLOADING MYSEJAHTERA");
	        	for(i=0;i<=6;i++)
	        	{
		            fordelay(100000000);
		            printf(".");
	       		}
	       		system("cls");
				menu();
			}
			while (new_choice != 'Y' && new_choice != 'N'){
				printf("\nError! Please re-enter your choice!");
				goto repeat;  
			}

            if (main_exit==1)
                    {
                    	system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    	system("cls");
                    	close();
					}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    }

        }
        return 0;
}
