#include<stdio.h>
#include<string.h>
#define MAX 100
struct Account {
	char accountId[20];
	char fullName[50];
	char phone[15];
	double balance;
	int status;
};

struct Transaction {
	char transId[20];
	char senderId[20];
	char receiverId[20];
	double amount;
	char type[10];
	char date[20];
};

struct Account accountList[MAX] = {
    {"AC1001","Nguyen Van A","0987000001",5000,1},
    {"AC1002","Tran Thi B","0987000002",6200,1},
    {"AC1003","Le Van C","0987000003",7400,1},
    {"AC1004","Pham Thi D","0987000004",5100,1},
    {"AC1005","Do Van E","0987000005",3300,1},
    {"AC1006","Nguyen Van F","0987000006",8800,1},
    {"AC1007","Hoang Thi G","0987000007",9200,1},
    {"AC1008","Bui Van H","0987000008",1500,1},
    {"AC1009","Dang Thi I","0987000009",2700,1},
    {"AC1010","Ngo Van J","0987000010",4600,1},

    {"AC1011","Nguyen Van K","0987000011",5100,1},
    {"AC1012","Le Thi L","0987000012",2300,1},
    {"AC1013","Pham Van M","0987000013",9000,1},
    {"AC1014","Tran Thi N","0987000014",7800,1},
    {"AC1015","Hoang Van O","0987000015",4100,1},
    {"AC1016","Do Thi P","0987000016",3200,1},
    {"AC1017","Bui Van Q","0987000017",1500,1},
    {"AC1018","Ngo Thi R","0987000018",2200,1},
    {"AC1019","Dang Van S","0987000019",3300,1},
    {"AC1020","Le Thi T","0987000020",9900,1},

    {"AC1021","Nguyen Van U","0987000021",7700,1},
    {"AC1022","Tran Thi V","0987000022",6600,1},
    {"AC1023","Pham Van W","0987000023",5500,1},
    {"AC1024","Do Thi X","0987000024",4300,1},
    {"AC1025","Hoang Van Y","0987000025",8000,1},
    {"AC1026","Le Thi Z","0987000026",9500,1},
    {"AC1027","Nguyen Thanh A","0987000027",3100,1},
    {"AC1028","Tran Minh B","0987000028",7200,1},
    {"AC1029","Pham Hong C","0987000029",5600,1},
    {"AC1030","Do Kieu D","0987000030",6400,1},

    {"AC1031","Hoang Bao E","0987000031",8700,1},
    {"AC1032","Nguyen Lan F","0987000032",9200,1},
    {"AC1033","Tran My G","0987000033",4800,1},
    {"AC1034","Le Quoc H","0987000034",3000,1},
    {"AC1035","Pham Tuan I","0987000035",5100,1},
};
int accountSize = 35;

struct Transaction transList[MAX] = {
    {"TR001","AC1001","AC1002",300,"SEND","2024-01-01"},
    {"TR002","AC1003","AC1004",200,"SEND","2024-01-02"},
    {"TR003","AC1005","AC1006",150,"SEND","2024-01-03"},
    {"TR004","AC1007","AC1008",330,"SEND","2024-01-04"},
    {"TR005","AC1009","AC1010",420,"SEND","2024-01-05"},

    {"TR006","AC1011","AC1012",510,"SEND","2024-01-06"},
    {"TR007","AC1013","AC1014",700,"SEND","2024-01-07"},
    {"TR008","AC1015","AC1016",120,"SEND","2024-01-08"},
    {"TR009","AC1017","AC1018",510,"SEND","2024-01-09"},
    {"TR010","AC1019","AC1020",300,"SEND","2024-01-10"},

    {"TR011","AC1021","AC1022",250,"SEND","2024-01-11"},
    {"TR012","AC1023","AC1024",340,"SEND","2024-01-12"},
    {"TR013","AC1025","AC1026",560,"SEND","2024-01-13"},
    {"TR014","AC1027","AC1028",620,"SEND","2024-01-14"},
    {"TR015","AC1029","AC1030",470,"SEND","2024-01-15"},

    {"TR016","AC1031","AC1032",800,"SEND","2024-01-16"},
    {"TR017","AC1033","AC1034",330,"SEND","2024-01-17"},
    {"TR018","AC1035","AC1001",440,"SEND","2024-01-18"},
    {"TR019","AC1002","AC1003",250,"SEND","2024-01-19"},
    {"TR020","AC1004","AC1005",310,"SEND","2024-01-20"},

    {"TR021","AC1006","AC1007",500,"SEND","2024-01-21"},
    {"TR022","AC1008","AC1009",270,"SEND","2024-01-22"},
    {"TR023","AC1010","AC1011",430,"SEND","2024-01-23"},
    {"TR024","AC1012","AC1013",150,"SEND","2024-01-24"},
    {"TR025","AC1014","AC1015",650,"SEND","2024-01-25"},

    {"TR026","AC1016","AC1017",220,"SEND","2024-01-26"},
    {"TR027","AC1018","AC1019",410,"SEND","2024-01-27"},
    {"TR028","AC1020","AC1021",350,"SEND","2024-01-28"},
    {"TR029","AC1022","AC1023",300,"SEND","2024-01-29"},
    {"TR030","AC1024","AC1025",600,"SEND","2024-01-30"},

    {"TR031","AC1026","AC1027",350,"SEND","2024-02-01"},
    {"TR032","AC1028","AC1029",420,"SEND","2024-02-02"},
    {"TR033","AC1030","AC1031",510,"SEND","2024-02-03"},
    {"TR034","AC1032","AC1033",240,"SEND","2024-02-04"},
    {"TR035","AC1034","AC1035",380,"SEND","2024-02-05"}
};
int transSize = 35;




void addAccount();
void updateInfor();
void lockAccount();
void searchAccount();
void showPagination();
void sortAccount();

int main() {
	int choice;
	
	while(1) {
		printf("\n+--------------------MENU--------------------+\n");
		printf("|%d. %-41s|\n",1,"Them tai khoan moi.");
		printf("|%d. %-41s|\n",2,"Cap nhat thong tin.");
		printf("|%d. %-41s|\n",3,"Quan li trang thai.");
		printf("|%d. %-41s|\n",4,"Tra cuu.");
		printf("|%d. %-41s|\n",5,"Danh sach.");
		printf("|%d. %-41s|\n",6,"Sap xep danh sach.");
		printf("|%d. %-41s|\n",7,"Giao dich/Chuyen khoan.");
		printf("|%d. %-41s|\n",8,"Lich su giao dich.");
		printf("|%d. %-41s|\n",9,"Thoat.");
		printf("+--------------------------------------------+\n");
		printf("Chon chuc nang: ");
		scanf("%d",&choice);
		getchar();
		switch(choice) {
			case 1:
				addAccount();
				break;
			case 2:
				updateInfor();
				break;
			case 3:
				lockAccount();
				break;
			case 4:
				searchAccount();
				break;
			case 5:
				showPagination();
				break;
			case 6:
				sortAccount();
		}
		
		
		if (choice == 9) {
			break;
		}
		
	}
	return 0;
}

// Them tai khoan
void addAccount() {
	if (accountSize >= MAX) {
		printf("Danh sach da day !!!");
		return;
	}
	
	while (1) {
 		printf("Nhap Ma ID: ");
 		fgets(accountList[accountSize].accountId,sizeof(accountList[accountSize].accountId),stdin);
 		accountList[accountSize].accountId[strcspn(accountList[accountSize].accountId,"\n")] = 0;
 		if (strlen(accountList[accountSize].accountId) == 0) {
 			printf("Khong duoc de trong - Vui long nhap ID !!!\n");
 			continue;
		}
		
		int existID = 0;
		for (int k = 0; k < accountSize; k++) {
			if (strcmp(accountList[accountSize].accountId,accountList[k].accountId) == 0) {
				existID = 1;
				break;
			}
		}
		if (existID) {
			printf("Ma ID da ton tai - Vui long nhap lai !!!\n");
			continue;
		}
		break;
	}
	
	while (1) {
		printf("Nhap Ho va Ten: ");
		fgets(accountList[accountSize].fullName,sizeof(accountList[accountSize].fullName),stdin);
 		accountList[accountSize].fullName[strcspn(accountList[accountSize].fullName,"\n")] = 0;
 		if (strlen(accountList[accountSize].fullName) == 0){
 			printf("Khong duoc de trong - Vui long nhap Ho va Ten !!!\n");
 			continue;
		 }
		 break;
	}
	
	while (1) {
		printf("Nhap SDT: ");
		fgets(accountList[accountSize].phone,sizeof(accountList[accountSize].phone),stdin);
 		accountList[accountSize].phone[strcspn(accountList[accountSize].phone,"\n")] = 0;
 		if (strlen(accountList[accountSize].phone) == 0) {
 			printf("SDT khong duoc de trong - Vui long nhap SDT !!!\n");
 			continue;
		 }
 		if (strlen(accountList[accountSize].phone) < 10 || strlen(accountList[accountSize].phone) > 10) {
 			printf("SDT khong hop le - Vui long nhap 10 so !!!\n");
 			continue;
		 }
 		break;	
	}
	accountList[accountSize].balance = 0;
	accountList[accountSize].status = 1;
	accountSize++;
	printf("Them tai khoan thanh cong !!!\n");
}

// Cap nhat tai khoan 
void updateInfor() {
	char id[20];
	int found = -1;
	while (1) {
		printf("Nhap Ma ID: ");
		fgets(id,sizeof(id),stdin);
		id[strcspn(id,"\n")] = 0;
		for (int i = 0; i < accountSize; i++) {
			
			if (strcmp(id,accountList[i].accountId) == 0) {
				found = i;
				break;
			}
		}
		if (found == -1) {
			printf("Loi khong tim thay tai khoan !!!\n");
			continue;
		}
		break;
	}
	
	printf("\n+---------------------Thong tin hien tai---------------------+\n");
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2f|%-10d|\n",accountList[found].accountId,accountList[found].fullName,accountList[found].phone,accountList[found].balance,accountList[found].status);
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	
	char name[50];
	printf("Nhap Ho va Ten: ");
	fgets(name,sizeof(name),stdin);
	name[strcspn(name,"\n")] = 0;
	if (strcmp(name,"") == 0) {
		printf("Thong tin duoc giu nguyen !!!\n");
	} else {
		strcpy(accountList[found].fullName,name);
	}
	
	while (1) {
		printf("Nhap SDT: ");
		fgets(accountList[accountSize].phone,sizeof(accountList[accountSize].phone),stdin);
 		accountList[accountSize].phone[strcspn(accountList[accountSize].phone,"\n")] = 0;
 		int isDuplicate = 0;
 		for (int i = 0; i < accountSize; i++)
	 		if (strcmp(accountList[accountSize].phone,accountList[i].phone) == 0) {
	 			isDuplicate = 1;
	 			break;
			 }
		if (isDuplicate == 1) {
			printf("SDT khong duoc trung voi tai khoan khac - Vui long nhap lai SDT !!!\n");
			continue;
		} 
 		if (strlen(accountList[accountSize].phone) != 10) {
 			printf("SDT khong hop le - Vui long nhap 10 so !!!\n");
 			continue;
		 }
 		break;
	}
	printf("Cap nhat thanh cong !!!\n");
}

//Khoa, Xoa tai khoan
void lockAccount() {
	char id[20];
	int found = -1;
	printf("Nhap Ma ID: ");
	fgets(id,sizeof(id),stdin);
	id[strcspn(id,"\n")] = 0;
	for (int i = 0; i < accountSize; i++) {
		
		if (strcmp(id,accountList[i].accountId) == 0) {
			found = i;
			break;
		}
	}
	if (found == -1) {
		printf("Loi khong tim thay tai khoan !!!\n");
		return;
	}
	printf("\n+---------------------Thong tin hien tai---------------------+\n");
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2f|%-10d|\n",accountList[found].accountId,accountList[found].fullName,accountList[found].phone,accountList[found].balance,accountList[found].status);
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	
	if (accountList[found].status == 0) {
		printf("Tai khoan da bi khoa !!!\n");
		return;
	}
	char confirm;
	printf("Xac nhan khoa tai khoan (y/n): ");
	confirm = getchar();
	if (confirm == 'Y' || confirm == 'y') {
		accountList[found].status = 0;
		printf("Da khoa tai khoan thanh cong !!!\n");
	} else if (confirm == 'N' || confirm == 'n') {
		printf("Huy thao tac !!!\n");
	}	
}

//Tim kiem 
void searchAccount() {
	char keyword[50];
	int found = -1;
	printf("Nhap Ma ID: ");
	fgets(keyword,sizeof(keyword),stdin);
	keyword[strcspn(keyword,"\n")] = 0;
	for (int i = 0; i < accountSize; i++) {
		
		if (strcmp(keyword,accountList[i].accountId) == 0 || strcmp(keyword,accountList[i].fullName) == 0) {
			found = i;
			break;
		}
	}
	if (found == - 1) {
		printf("Khong co ket qua phu hop !!!\n");
		return;
	}
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2f|%-10d|\n",accountList[found].accountId,accountList[found].fullName,accountList[found].phone,accountList[found].balance,accountList[found].status);
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	
}

// Danh sach trang
void showPagination() {
	int page_number = 0, page_size = 10;
	int page = accountSize / page_size;
	int total_pages = (accountSize % page_size == 0) ? page: page + 1;
	while (1) {
		printf("Nhap so trang (1 - %d): ",total_pages);
		scanf("%d",&page_number);
		if (page_number < 0 || page_number > total_pages) {
			printf("Loi du lieu khong hop le !!\n");
			continue;
		}
		break;
	}
	int start = (page_number - 1) * page_size;
	int end = start + page_size;
	printf("\n+--------------------------------------Trang %d/%d-------------------------------------+\n",page_number,total_pages);
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	for (int i = start; i < end && i < accountSize; i++) {
		printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2f|%-10d|\n",accountList[i].accountId,accountList[i].fullName,accountList[i].phone,accountList[i].balance,accountList[i].status);
	}
	
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	
}

//Sap xep
void sortAccount() {
	int choice;
	printf("+-------Sap xep--------+\n");
	printf("|%d. %-19s|\n",1,"Theo so du giam dan");
	printf("|%d. %-19s|\n",2,"Theo ten A-Z");
	printf("+----------------------+\n");
	printf("Nhap lua chon: ");
	scanf("%d",&choice);
	
	struct Account temp;
	switch(choice) {
		case 1:
			for (int i = 0; i < accountSize - 1; i++) {
				for (int j = 0; j < accountSize - i - 1; j++) {
					if (accountList[j].balance < accountList[j + 1].balance) {
						temp = accountList[j];
						accountList[j] = accountList[j + 1];
						accountList[j + 1] = temp;	
					}	
				}
			}
			printf("Da sap xep xong !!!\n");
			break;
			
		case 2: 
			for (int i = 0; i < accountSize; i++) {
				for (int j = i + 1; j < accountSize; j++) {
					if (strcmp(accountList[i].fullName, accountList[j].fullName) > 0) {
						struct Account temp = accountList[i];
						accountList[i] = accountList[j];
						accountList[j] = temp;
					}
				}
			}
			printf("Da sap xep xong !!!\n");
			break;
		}
	}

