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
    {"AC1001", "Nguyen Van A", "0987654321", 5000000, 1},
    {"AC1002", "Tran Thi B",  "0912345678", 12000000, 1},
    {"AC1003", "Le Van C",    "0935123456", 8500000, 0}, 
    {"AC1004", "Pham Thi D",  "0909988776", 3000000, 1},
    {"AC1005", "Hoang Van E", "0977554466", 20000000, 1}
};
int accountSize = 5;

struct Transaction transList[MAX] = {
    {"T0001", "AC1001", "AC1002", 1500000, "SEND", "2024-11-10"},
    {"T0002", "AC1002", "AC1001", 500000,  "SEND", "2024-11-12"},
    {"T0003", "AC1004", "AC1005", 2000000, "SEND", "2024-11-15"},
    {"T0004", "AC1005", "AC1001", 1000000, "SEND", "2024-11-17"},
    {"T0005", "AC1001", "AC1004", 300000,  "SEND", "2024-11-20"}
};
int transSize = 5;

int size;


void addAccount();
void updateInfor();
void lockAccount();

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
		printf("Thong tin duoc giu nguyen !!!");
	} else {
		strcpy(accountList[found].fullName,name);
	}
	
	while (1) {
		printf("Nhap SDT: ");
		fgets(accountList[accountSize].phone,sizeof(accountList[accountSize].phone),stdin);
 		accountList[accountSize].phone[strcspn(accountList[accountSize].phone,"\n")] = 0;
 		int isDuplicate = 0;
 		for (int i = 0; i < accountSize; i++)
	 		if (strcmp(accountList[accountSize].phone ,accountList[i].phone)) {
	 			isDuplicate = 1;
	 			break;
			 }
		if (isDuplicate) {
			printf("SDT khong duoc trung voi tai khoan khac - Vui long nhap lai SDT !!!\n");
			continue;
		} 
 		if (strlen(accountList[accountSize].phone) < 10 || strlen(accountList[accountSize].phone) > 10) {
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
		printf("Khong tim thay tai khoan !!!\n");
		return;
	}
	printf("\n+---------------------Thong tin hien tai---------------------+\n");
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2f|%-10d|\n",accountList[found].accountId,accountList[found].fullName,accountList[found].phone,accountList[found].balance,accountList[found].status);
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	
	char confirm;
	printf("Xac nhan khoa tai khoan (y/n): ");
	scanf("%c",&confirm);
	if (confirm == 'Y' || confirm == 'y') {
		accountList[found].status = 0;
		printf("Da khoa tai khoan thanh cong !!!\n");
	} else if (confirm == 'N' || confirm == 'n') {
		printf("Huy thao tac !!!\n");
	}	
}
