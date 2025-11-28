#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
struct Account {
	char accountId[20];
	char fullName[50];
	char phone[15];
	double balance; // So du
	int status;
};

struct Transaction {
	char transId[20]; //Ma giao dich
	char senderId[20]; // Ma nguoi gui
	char receiverId[20]; // Ma nguoi nhan
	double amount;
	char type[10]; // Trang thai
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
int accountSize = 35; // Kich thuoc cua Account

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
int transSize = 35;// Kich thuoc cua Transaction




void addAccount(); // Them tai khoan
void updateInfor(); // Cap nhat 
void lockAccount(); // Khoa tai khoan
void toLower(); // Chuyen sang chu thuong
void searchAccount(); // Tim kiem tai khoan
void showPagination(); // Danh sach phan trang
void sortAccount(); // Sap xep 
void transferMoney(); // Giao dich
void autoIncreasingTransId(char newId[]); // Tu dong tang ID
void getCurrentTime(char date[]);
void viewTransactionHistory();


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
				break;
			case 7:
				transferMoney();
				break;
			case 8:
				viewTransactionHistory();
				break;
			case 9:
				printf("Ban da thoat chuong trinh !!!\n");
				break;
			default:
				printf("Loi - Vui long nhap lai !!\n");
				break;
		}
		if (choice == 9) {
			break;
		}		
	}
	return 0;
}

// Them tai khoan
void addAccount() {
	int isDigit;
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
		 
		isDigit = 1;
		for (int i = 0; i < strlen(accountList[accountSize].phone); i++) {
			if (!isdigit(accountList[accountSize].phone[i])) {
				isDigit = 0;
				break;
			}
		}
		if (isDigit == 0) {
			printf("SDT chi duoc phep nhap so !!\n");
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
	int isDigit;
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
	
	printf("\n+---------------------------------Thong tin hien tai---------------------------------+\n");
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2lf|%-10s|\n",accountList[found].accountId,accountList[found].fullName,accountList[found].phone,accountList[found].balance,accountList[found].status == 1 ? "Active" : "Locked");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	
	char name[50];
	printf("Nhap Ho va Ten: ");
	fgets(name,sizeof(name),stdin);
	name[strcspn(name,"\n")] = 0;
	if (strlen(name) > 0) {
		strcpy(accountList[found].fullName,name);
	}
	
	while (1) {
		printf("Nhap SDT: ");
		fgets(accountList[found].phone,sizeof(accountList[found].phone),stdin);
 		accountList[found].phone[strcspn(accountList[found].phone,"\n")] = 0;
 		
 		isDigit = 1;
		for (int i = 0; i < strlen(accountList[found].phone); i++) {
			if (!isdigit(accountList[found].phone[i])) {
				isDigit = 0;
				break;
			}
		}
		if (isDigit == 0) {
			printf("SDT chi duoc phep nhap so !!\n");
			continue;
		}
		
 		int isDuplicate = 0;
 		for (int i = 0; i < accountSize; i++) {
 			if (i == found) {
 				continue;
			}
	 		if (strcmp(accountList[found].phone,accountList[i].phone) == 0) {
	 			isDuplicate = 1;
	 			break;
			} 
		}
		if (isDuplicate == 1) {
			printf("SDT khong duoc trung voi tai khoan khac - Vui long nhap lai SDT !!!\n");
			continue;
		} 
		
 		if (strlen(accountList[found].phone) != 10) {
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
	
	printf("\n+---------------------------------Thong tin hien tai---------------------------------+\n");
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2lf|%-10s|\n",accountList[found].accountId,accountList[found].fullName,accountList[found].phone,accountList[found].balance,accountList[found].status == 1 ? "Active" : "Locked");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	
	if (accountList[found].status == 0) {
		printf("Tai khoan da bi khoa !!!\n");
		return;
	}
	while (1) {
		char confirm;
		printf("Xac nhan khoa tai khoan (y/n): ");
		confirm = getchar();
		fflush(stdin);
		if (confirm == 'Y' || confirm == 'y') {
			accountList[found].status = 0;
			printf("Da khoa tai khoan thanh cong !!!\n");
			return;
		} else if (confirm == 'N' || confirm == 'n') {
			printf("Huy thao tac !!!\n");
			return;
		} else {
			printf("Vui long nhap (y/n) !!!\n");
		}
	}
}

//Chuyen thanh chu thuong
void toLower(char str[]) {
	for (int i = 0; str[i] != 0; i++) {
		str[i] = tolower(str[i]);
	}
} 

//Tim kiem 
void searchAccount() {
	char keyword[50];
	char lowerKeyword[50];
	char lowerId[20];
	char lowerName[50];
	int found = -1;
	printf("Nhap Ma ID hoac Ho Ten: ");
	fgets(keyword,sizeof(keyword),stdin);
	keyword[strcspn(keyword,"\n")] = 0;
	strcpy(lowerKeyword,keyword);
	toLower(lowerKeyword);// Chuyen keyword sang chu thuong
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	for (int i = 0; i < accountSize; i++) {
		//Sao chep chuoi
		strcpy(lowerId,accountList[i].accountId);
		strcpy(lowerName,accountList[i].fullName);
		toLower(lowerId);// Chuyen ID sang chu thuong
		toLower(lowerName);// Chuyen Name sang chu thuong
		if (strstr(lowerId,lowerKeyword) != NULL || strstr(lowerName,lowerKeyword) != NULL) {
			found = i;
			printf("+----------+------------------------------+----------+--------------------+----------+\n");
			printf("|%-10s|%-30s|%-10s|%-20.2lf|%-10s|\n",accountList[i].accountId,accountList[i].fullName,accountList[i].phone,accountList[i].balance,accountList[i].status == 1 ? "Active" : "Locked");
			printf("+----------+------------------------------+----------+--------------------+----------+\n");
		}
		
	}
	if (found == - 1) {
		printf("Khong co ket qua phu hop !!!\n");
		return;
	}
	
}

// Danh sach trang
void showPagination() {
	if (accountSize == 0) {
		printf("Danh sach trong !!!\n");
		return;
	}
	int page_number; // so cua trang
	int page_size = 10;
	int page = accountSize / page_size;
	int total_pages = (accountSize % page_size == 0) ? page: page + 1;
	while (1) {
		printf("Nhap so trang (1 - %d): ",total_pages);
		scanf("%d",&page_number);
		getchar();
		if (page_number < 1 || page_number > total_pages) {
			printf("Loi du lieu khong hop le !!\n");
			continue;
		}
		
		int start = (page_number - 1) * page_size;
		int end = start + page_size;
		printf("\n+--------------------------------------Trang %d/%d-------------------------------------+\n",page_number,total_pages);
		printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
		printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
		for (int i = start; i < end && i < accountSize; i++) {
			printf("+----------+------------------------------+----------+--------------------+----------+\n");
			printf("|%-10s|%-30s|%-10s|%-20.2lf|%-10s|\n",accountList[i].accountId,accountList[i].fullName,accountList[i].phone,accountList[i].balance,accountList[i].status == 1 ? "Active" : "Locked");
		}
		printf("+----------+------------------------------+----------+--------------------+----------+\n");
		
		while (1) {
			char confirm;
			printf("Ban co muon xem trang khac khong ? (y/n): ");
			confirm = getchar();
			fflush(stdin);
			if (confirm == 'Y' || confirm == 'y') {
				break;
			} else if (confirm == 'N' || confirm == 'n') {
				return;
			} else {
				printf("Vui long nhap (y/n) !!!\n");
			}
		}
	}	
}

//Sap xep tai khoan
void sortAccount() {
	if (accountSize == 0) {
		printf("Khong co du lieu de sap xep !!!\n");
		return;
	}
	int choice;
	printf("+-------Sap xep--------+\n");
	printf("|%d. %-19s|\n",1,"Theo so du giam dan");
	printf("|%d. %-19s|\n",2,"Theo ten A-Z");
	printf("+----------------------+\n");
	while (1) {
		printf("Nhap lua chon(1 hoac 2): ");
		scanf("%d",&choice);
		getchar();
		if (choice == 1 || choice == 2) {
			break;
		}
		printf("Loi du lieu nhap vao - Vui long nhap lai !!!\n");
		continue;
	}
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
				for (int j = 0; j < accountSize - i - 1; j++) {
					if (strcmp(accountList[j].fullName, accountList[j + 1].fullName) > 0) {
						struct Account temp = accountList[j];
						accountList[j] = accountList[j + 1];
						accountList[j + 1] = temp;
					}
				}
			}
			printf("Da sap xep xong !!!\n");
			break;
		}
	}

void autoIncreasingTransId(char id[]) {
	int lenght = strlen(id);
	int pos = lenght - 1;
	
	while (pos >= 0 && isdigit(id[pos])) {
		pos--;
	}
	pos++; // pos = 2
	
	char prefix[20];
	char number[20];
	
	strncpy(prefix,id,pos);
	prefix[pos] = '\0';
	strcpy(number,id + pos);
	
	// chuyen so o dang chuoi sang so nguyen
	int num = strtol(number,NULL,10); // strtol(chuoi chu so can chuyen, vi tri ket thuc, dinh dang)
	num++;
	
	char newNumber[20];
	sprintf(newNumber,"%0*d",strlen(number),num); // sprintf(mang luu ket qua,chinh dinh dang,kich thuoc,ket qua can luu)
	
	strcpy(id,prefix);
	strcat(id,newNumber);
}	

// Lay thoi gian tu he thong
void getCurrentTime(char date[]) {
	// time_t : mot kieu so nguyen de luu Calendar Time
	// struct tm : Cau truc de luu tru date va time
	// time(NULL): lay thoi gian hien tai theo gio dia phuong
	time_t t = time(NULL);
	struct tm tm = *localtime(&t); // *localtime(&t): Lay gia tri struct -> luu vao tm
	sprintf(date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	/*
	tm_mday: Ngay 1 - 31
	tm_mon: Thang 0 - 11
	tm_year: Tinh tu nam 1900
	*/
}	

// Giao dich/Chuyen khoan
void transferMoney() {
	char today[20];
	char newTransId[20];
	char senderId[20];
	char receiverId[20];
	double amount = 0;
	int foundSenderID;
	int foundReceiverID;
	while (1) {
		printf("Nhap ID nguoi gui: ");
		fgets(senderId,sizeof(senderId),stdin);
		senderId[strcspn(senderId,"\n")] = 0;
		
		if (strcmp(senderId,"") == 0) {
			printf("Vui long nhap ID nguoi gui !!!\n");
			continue;
		}
		// Tim kiem ID nguoi gui
		foundSenderID = -1;
		for (int i = 0; i < accountSize; i++) {
			if (strcmp(senderId,accountList[i].accountId) == 0) {
				foundSenderID = i;
				break;
			}
		}
		if (foundSenderID == -1) {
			printf("Khong tim thay tai khoan !!\n");
			continue;
		}
		
		if (accountList[foundSenderID].status == 0) {
			printf("Tai khoan da bi khoa - Khong the thuc hien gia dich !!\n");
			return;
		}
		break;	
	}
	
	while (1) {
		printf("Nhap ID nguoi nhan: ");
		fgets(receiverId,sizeof(receiverId),stdin);
		receiverId[strcspn(receiverId,"\n")] = 0;
		
		if (strcmp(receiverId,"") == 0) {
			printf("Vui long nhap ID nguoi nhan !!!\n");
			continue;
		}
		// Tim kiem ID nguoi nhan
		foundReceiverID = -1;
		for (int i = 0; i < accountSize; i++) {
			if (strcmp(receiverId,accountList[i].accountId) == 0) {
				foundReceiverID = i;
				break;
			}
		}
		if (foundReceiverID == -1) {
			printf("Khong tim thay tai khoan !!\n");
			continue;
		}
		// Kiem tra trung lap ID
		if (strcmp(receiverId,senderId) == 0) {
			printf("ID nguoi nhan trung voi ID nguoi gui - Vui long nhap lai !!\n");
			continue;
		}
		if (accountList[foundReceiverID].status == 0) {
			printf("Tai khoan da bi khoa - Khong the thuc hien giao dich !!\n");
			return;
		}
		break;
	}
	
	while (1) {
		printf("Nhap so tien: ");
		scanf("%lf",&amount);
		getchar();
		
		if (amount < 0) {
			printf("So ten phai lon hon 0 - Vui long nhap lai !!\n");
			continue;
		}
		
		if (amount > accountList[foundSenderID].balance) {
			printf("So du khong du !!\n");
			continue;
		}
		break;
	}
	accountList[foundSenderID].balance -= amount;
	accountList[foundReceiverID].balance += amount;
	printf("Chuyen khoan thanh cong !!\n");
	
	getCurrentTime(today); // Lay ngay hien tai
	int pos = transSize - 1;
	
	strcpy(newTransId,transList[pos].transId);
	autoIncreasingTransId(newTransId); // Tang ID len 1 don vi
	strcpy(transList[transSize].transId,newTransId);
	strcpy(transList[transSize].senderId,senderId);
	strcpy(transList[transSize].receiverId,receiverId);
	transList[transSize].amount = amount;
	strcpy(transList[transSize].type,"SEND");
	strcpy(transList[transSize].date,today);
	transSize++; 	
}

void viewTransactionHistory() {
	char targetId[20];
	int foundId;
	int foundTrans;
	while (1) {
		printf("Nhap Ma tai khoan: ");
		fgets(targetId,sizeof(targetId),stdin);
		targetId[strcspn(targetId,"\n")] = 0;
		
		if (strlen(targetId) == 0) {
			printf("Vui long nhap Ma tai khoan !!\n");
			continue;
		}
		// Kiem tra tai khoan co ton tai ko ?
		foundId = -1;
		for (int i = 0; i < accountSize; i++) {
			if (strcmp(targetId,accountList[i].accountId) == 0) {
				foundId = i;
				break;
			}
		}
		if (foundId == -1) {
			printf("Tai khoan khong ton tai !!\n");
			continue;
		}
		
		// Kiem tra giao dich
		foundTrans = 0;
		for (int j = 0; j < transSize; j++) {
			 if (strcmp(targetId, transList[j].senderId) == 0 || strcmp(targetId, transList[j].receiverId) == 0) {
				foundTrans = 1;
				break;
			}
		}
		if (foundTrans == 0) {
			printf("He thong chua co giao dich nao !!\n");
			return;
		}
		break;
	}
	printf("+------------+------------+-------------+--------------+--------------+--------------------+\n");
	printf("|%-12s|%-12s|%-13s|%-14s|%-14s|%-20s|\n","Ma giao dich","Ma nguoi gui","Ma nguoi nhan","Tien gui","Tien nhan","Trang thai","Ngay thang");
	printf("+------------+------------+-------------+--------------+--------------+--------------------+\n");
	for (int k = 0; k < transSize; k++) {
		if (strcmp(targetId, transList[k].senderId) == 0 || strcmp(targetId, transList[k].receiverId) == 0) {
			
			double moneySend = 0;
            double moneyReceive = 0;

            if (strcmp(targetId, transList[k].senderId) == 0) {
            	moneySend = transList[k].amount;
            	strcpy(transList[k].type,"DA GUI");
			}
                
            if (strcmp(targetId, transList[k].receiverId) == 0) {
            	moneyReceive = transList[k].amount;
            	strcpy(transList[k].type,"DA NHAN");
			}
                
			printf("|%-12s|%-12s|%-13s|%-14.2lf|%-14.2lf|%-20s|\n",transList[k].transId,transList[k].senderId,transList[k].receiverId,moneySend,moneyReceive,transList[k].type,transList[k].date);	
		} 	
	}
	printf("+------------+------------+-------------+--------------+--------------+--------------------+\n");
}
