#include "books.h"

// 애플리케이션용 함수 원형
void create_record(); //
void read_record(); //
void update_record(); //
void delete_record(); //
void list_record(); //
void search_name(); //
void search_writer(); //
void search_publisher(); //
void search_status(); //
void search_location();
void sort_record(); //
void load_file(); //
void save_file(); //
void debug_records(); // for debug 

int main()
{
	b_init();
	int menu;
	while(1){
		printf("\nMenu : 1.Create 2.Read 3.Update 4.Delete 5.List");
		printf("\n6:Search(name) 7.Search(writer) 8.Search(publisher) 9.Search(status)");
		printf("\n10.Search(location) 11.Sort 12.Load 13.Save 0.Quit > ");
		scanf("%d", &menu);
		printf("\n");
		switch(menu){
			case 1:
				create_record();
				break;
			case 2:
				read_record();
				break;
			case 3:
				update_record();
				break;
			case 4:
				delete_record();
				break;
			case 5:
				list_record();
				break;
			case 6:
				search_name();
				break;
			case 7:
				search_writer();
				break;
			case 8:
				search_publisher();
				break;
			case 9:
				search_status();
				break;
			case 10:
				search_location();
				break;
			case 11:
				sort_record();
				break;
			case 12:
				load_file();
				break;
			case 13:
				save_file();
				break;
			case 15:
				debug_records();
				break;
			case 0:
			default:
				return 0;
		}
	}
    return 0;
}

void create_record(){
	if(!b_is_available()) {
		printf("There is no space!\n");
		return;
	}
	char name[50], writer[50], publisher[20], location[20];
	int status;  
	printf("Enter a new book's info.\n");
	printf("Name > ");
	getchar();
	scanf("%[^\n]s", name);
	getchar();
	if(b_search_by_name(name)) {
	    printf("Duplicated name!\n");
		return;
    }
	printf("Writer > ");
	scanf("%[^\n]s", writer);
	getchar();
	printf("publisher > ");
	scanf("%s", publisher);
	printf("Status(possible:1 impossible:0) > ");
	scanf("%d", &status);
	printf("Location > ");
	scanf("%s", location);
	b_create(name, writer, publisher, status, location);
}

void read_record(){
	char name[50];
	printf("Enter a name > ");
	getchar();
	scanf("%[^\n]s", name);
	getchar();
	
	T_Record* p = b_search_by_name(name);
	if(p) {
	    printf("Book info.\n");
		printf("Name : %s\n", b_getname(p));
		printf("Writer : %s\n", b_getwriter(p));
		printf("Publisher : %s\n", b_getpublisher(p));
		printf("Status : %d\n", b_getstatus(p));
		printf("Location : %s\n", b_getlocation(p));
	}
	else {
	    printf("No such book!\n");
	}
}

void update_record(){

}

void delete_record(){

}

void list_record(){
// 전체 리스트 출력
    printf("All records.\n");
	int size = b_count();
	T_Record* records[MAX_BOOKS];
	b_get_all(records);
	for(int i=0; i<size; i++){
	    T_Record* p = records[i];
	    printf("%d. %s\n", i+1, b_to_string(p));
	}
}

void search_name(){

}

void search_writer(){

}

void search_publisher(){

}

void search_status(){

}

void search_location(){

}

void sort_record(){

}

void load_file(){
// 데이터파일 읽기
    printf("All data will be deleted and new records will be reloaded.\n");
    printf("1.Yes 0.No > ");
    int yesno;
    scanf("%d", &yesno);
	if (yesno == 0) return;

    b_init();   // 레코드 모두 제거 

	FILE* f = fopen("books.txt", "r");
	char name[50], writer[50], publisher[20], location[20];
	int status;  
	while(!feof(f)){
		if(!b_is_available()) {
			printf("[Load] There is no space!\n");
			break;
		}
		int n = fscanf(f,"%[^\n]s", name);
		fgetc(f);
		n+=fscanf(f,"%[^\n]s", writer);
		n+=fscanf(f,"%s %d %s", publisher, &status, location);
		fgetc(f);
		if (n<5) break;
		if(b_search_by_name(name)) {
			printf("[Load] Duplicated name(%s)! loading.\n", name);
			continue;
		}
		b_create(name, writer, publisher, status, location);
		//printf("[Load] load %s\n", name);
	}
	printf("%d records are read from file!\n", b_count());    
	fclose(f);
}

void save_file(){
	FILE* f=fopen("books.txt", "w");
	printf("All records.\n");
	int size=b_count();
	T_Record* records[MAX_BOOKS];
	b_get_all(records);
	for(int i=0;i<size;i++){
		T_Record* p=records[i];
		fprintf(f,"%s\n", b_to_string_save(p));
	}
	fclose(f);
}

void debug_records(){

}































