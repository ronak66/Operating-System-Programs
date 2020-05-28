/*Program to create three or more records in a file*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

typedef struct normalUser{
	int userID;
	char name[30];
	char password[10];
	int account_no;
	float balance;
	char status[20];
}normalUser;

typedef struct jointUser{
	int userID;
	char name1[30];
	char name2[30];
	char password[10];
	int account_no;
	float balance;
	char status[20];
}jointUser;

typedef struct admin{
	int userID;
	char username[30];
	char password[10];
}admin;

int getNewUserID1();
int getNewUserID2();
int getNewUserID3();

int getNewUserID1(){
	int fd=open("NUfile",O_RDONLY,0744);
	normalUser record;
	lseek(fd,-sizeof(normalUser),SEEK_END);
	read(fd,&record,sizeof(normalUser));
	close(fd);
	return record.userID+1;
}

int getNewUserID2(){
	int fd=open("JUfile",O_RDONLY,0744);
	jointUser record;
	lseek(fd,-sizeof(jointUser),SEEK_END);
	read(fd,&record,sizeof(jointUser));
	close(fd);
	return record.userID+1;
}

int getNewUserID3(){
	int fd=open("ADfile",O_RDONLY,0744);
	admin record;
	lseek(fd,-sizeof(admin),SEEK_END);
	read(fd,&record,sizeof(admin));
	close(fd);
	return record.userID+1;
}

int main(){
	int fd=open("ADfile",O_RDWR | O_CREAT,0744);
	int choice=0;
	admin newAdmin;
	printf("Please enter the name of the admin: ");
	scanf(" %s",newAdmin.username);
	printf("Please enter the password(max 10 characters): ");
	scanf(" %s",newAdmin.password);
	newAdmin.userID=1000;
	printf("Your userID is : %d\n",newAdmin.userID);
	write(fd,&newAdmin,sizeof(newAdmin));
	printf("Do you want to continue(0/1)? ");
	scanf("%d",&choice);
	while(choice){
		printf("Please enter the name of the admin: ");
		scanf(" %[^\n]",newAdmin.username);
		printf("Please enter the password(max 10 characters): ");
		scanf(" %[^\n]",newAdmin.password);
		newAdmin.userID=getNewUserID3();
		printf("Your userID is : %d\n",newAdmin.userID);
		write(fd,&newAdmin,sizeof(admin));
		printf("Do you want to continue(0/1)? ");
		scanf("%d",&choice);
	}
	close(fd);

	fd=open("NUfile",O_RDWR | O_CREAT,0744);
	choice=1;
	normalUser newNUser;
	printf("Please enter the name of the normal user: ");
	scanf(" %[^\n]",newNUser.name);
	printf("Please enter the password(max 10 characters): ");
	scanf(" %[^\n]",newNUser.password);
	newNUser.userID=1000;
	newNUser.balance=1000;
	newNUser.account_no=(newNUser.userID-1000)+100000;
	printf("Your userID is : %d\n",newNUser.userID);
	strcpy(newNUser.status,"ACTIVE");
	write(fd,&newNUser,sizeof(normalUser));
	printf("Do you want to continue(0/1)? ");
	scanf("%d",&choice);
	while(choice){
		printf("Please enter the name of the normal user: ");
		scanf(" %[^\n]",newNUser.name);
		printf("Please enter the password(max 10 characters): ");
		scanf(" %[^\n]",newNUser.password);
		newNUser.userID=getNewUserID1();
		newNUser.balance=1000;
		newNUser.account_no=(newNUser.userID-1000)+100000;
		printf("Your userID is : %d\n",newNUser.userID);
		strcpy(newNUser.status,"ACTIVE");
		write(fd,&newNUser,sizeof(normalUser));
		printf("Do you want to continue(0/1)? ");
		scanf("%d",&choice);
	}
	close(fd);

	fd=open("JUfile",O_RDWR | O_CREAT,0744);
	choice=1;
	jointUser newJUser;
	printf("Please enter the main name of the joint user: ");
	scanf(" %[^\n]",newJUser.name1);
	printf("Please enter the second name of the joint user: ");
	scanf(" %[^\n]",newJUser.name2);
	printf("Please enter the password(max 10 characters): ");
	scanf(" %[^\n]",newJUser.password);
	newJUser.userID=1000;
	newJUser.balance=1000;
	newJUser.account_no=(newJUser.userID-1000)+100000;
	printf("Your userID is : %d\n",newJUser.userID);
	strcpy(newJUser.status,"ACTIVE");
	write(fd,&newJUser,sizeof(jointUser));
	printf("Do you want to continue(0/1)? ");
	scanf("%d",&choice);
	while(choice){
		printf("Please enter the main name of the joint user: ");
		scanf(" %[^\n]",newJUser.name1);
		printf("Please enter the second name of the joint user: ");
		scanf(" %[^\n]",newJUser.name2);
		printf("Please enter the password(max 10 characters): ");
		scanf(" %[^\n]",newJUser.password);
		newJUser.userID=getNewUserID2();
		newJUser.balance=1000;
		newJUser.account_no=(newJUser.userID-1000)+100000;
		printf("Your userID is : %d\n",newJUser.userID);
		strcpy(newJUser.status,"ACTIVE");
		write(fd,&newJUser,sizeof(jointUser));
		printf("Do you want to continue(0/1)? ");
		scanf("%d",&choice);
	}
	close(fd);
	return 0;
}


