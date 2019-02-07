
// C Program for Message Queue (Writer Process) 
 #include <stdio.h> 
 #include <sys/ipc.h> 
 #include <sys/msg.h> 
 #include <stdlib.h> 
 #include<sys/types.h>
   // structure for message queue 
   struct msg_buffer
{ 
       long mesg_type; 
       char mesg_text[100]; 
 };            
            
int main() 
            {  
		 struct msg_buffer message;
                 key_t key; 
                 int msgid; 
                       
                 // ftok to generate unique key 
                if ((key = ftok("/home/epl/Desktop/Gowda/IPC/file.txt", 65))==-1)
		{
		perror("key");
        	exit(1);	
		}                 
                 // msgget creates a message queue 
                 // and returns identifier 
                if ((msgid = msgget(key, 0666 | IPC_CREAT)==-1))
				{
                                perror("msgid");
				exit(1);
				}
                 message.mesg_type = 1; 
                                                   
                 printf("Write Data : "); 
                 scanf("%s",message.mesg_text); 
                                                             
                 // msgsnd to send message 
                 msgsnd(msgid, &message, sizeof(message), 0); 
                                                                       
                 printf("Data send is : %s \n", message.mesg_text); 
                                                                                
                 return 0; 
             } 
