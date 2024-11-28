/************************************************************************************************************************************
*   Source File Name :   LGY_CPU_Scheduler                                                                                          *
*   Project Name:        LGY_CPU_Scheduler                                                                                          *
*   Engineer:            赖国勇                                                                                                     *
*   Date Generated:      2007-11-19                                                                                                 *
*   Last Revision Date:  2023-12-15                                                                                                 *
*   Brief Description:	                                                                                                            *
*	[实验概要]                                                                                                                      *
*	①、实验目的                                                                                                                    *
*		a、进程调度是处理机管理的核心内容。观察、体会操作系统的进程调度方法，                                                       *
*		并通过一个简单的进程调度算法模拟系统的实现，加深对进程控制块、进程队列、进程调度算法，进程切换的理解，                      *
*		并体会和了解各种调度算法的具体实施办法。                                                                                    *
*		b、提高实际动手编程能力，为日后从事软件开发工作打下坚实基础。                                                               *
*	②、实验内容                                                                                                                    *
*		a、设计进程控制块PCB表结构，模拟实现进程调度算法：FIFO，静态优先级调度，                                                    *
*		时间片轮转调度，短进程优先调度算法，多级反馈队列调度。（实现其中之一个以上）。                                              *
*		b、编写一个进程调度算法模拟系统。模拟系统只对被调度进程的PCB进行相应的模拟调度操作，被调度进程不需要实际代码和被处理数据。  *
*		c、由用户输入（可通过文件输入）进程名、进程状态、进程运行时间和进程优先数等数据。                                           *
*	③、实验要求                                                                                                                    *
*		a、使用模块化设计思想来设计；                                                                                               *
*		b、实验报告要求给出主函数和各个算法函数的流程图。                                                                           *
*		c、学生可按照自身条件，随意选择采用的算法，（例如：采用选择排序或者冒泡排序编写程序，实现短进程优先调度的算法）             *
*		d、进程调度算法模拟系统只对被调度进程的PCB进行相应的模拟调度操作，被调度进程不需要实际代码和被处理数据。                    *
*	④、运行结果                                                                                                                    *
*		a、给出对被调度进程的PCB进行相应的模拟调度操作的结果。                                                                      *
*	⑤、提示                                                                                                                        *
*		a、每个进程可有三个状态（1就绪 2等待 3运行），并假设初始状态为就绪状态。                                                    *
*		b、为了便于处理，程序中的进程运行时间以纳秒为单位计算。                                                                     *
*		c、各进程的优先数或轮转时间片长度以及进程需运行的时间的初始值均由用户给定。                                                 *
*		d、在优先级算法中，采用静态优先级。在时间片轮转算法中，采用可变时间片，由用户给定。                                         *
*		e、对于遇到运行时间或优先级相同的情况，采用FIFO策略解决。                                                                   *
*		f、输入：进程流文件（文本文件），其中存储的是一系列要执行的进程，每个进程包括至少四个数据项：进程名、进程状态（1就绪 2等待  *
*                 3运行）、所需时间、优先数（0最高）。                                                                              *
*		g、输出：进程调度执行流、等待时间、平均等待时间等。                                                                         *
*                                                                                                                                   *
*    一、 本进程调度算法模拟系统包括:FIFO，短进程优先调度算法，优先级调度算法（静态优先级），时间片轮转调度算法。                   *
*    	 VC++6.0调试通过  项目类型：Win32 Console Application                                                                       *
*    	输入：进程流文件（文本文件），其中存储的是一系列要执行的进程，每个进程包括四个数据项：                                      *
*    	 	进程名、进程状态（1就绪 2等待 3运行）、所需时间、优先数（数字越小优先级越高）                                           *
*    	输出：进程调度执行流、等待时间、平均等待时间等。                                                                            *
*	 二、在WINDOWS中双击DEBUG目录中的EXE文件直接运行，可能会没有显示结果窗口就关闭了，这不是程序错误，解决方法是：                  *
*    	1、“开始->程序->附件-命令提示符”,打开DOS命令窗口。                                                                        *
*    	2、改变当前目录至EXE文件所在目录；（或者将EXE文件和测试用的文本文件一并复制到当前目录）。                                   *
*    	3、输入EXE文件的完整名称（含后缀名）运行即可。（为简化输入，可以重命名EXE文件。）                                           *
*************************************************************************************************************************************/


#include<stdio.h> 
#include<string.h> 
#include<iostream>

using namespace std;

const int MAXPCB=200;	//定义最多进程数 


//定义进程控制块PCB结构体类型 
typedef struct PCB_Node{ 
	char sName[20];		//进程名
	int iStatus;		//进程状态（1就绪 2等待 3运行） 当前系统中暂时全部默认为就绪处理
	int iRunTime; 		//进程运行时间（纳秒）
	int iPriority; 		//进程优先数（数字越小优先级越高） 
	int iBeFinished; 	//进程是否执行完成标志（1：已完成；0：末完成）
	int iWaitTime; 		//进程等待时间（纳秒）
}PCB; 

PCB pcbs[MAXPCB];		//PCB数组（队列） 

int iPCBNum=0;			//实际进程数
char sFileName[20];		//进程流文件名
int iSumWaitTime=0;		//总等待时间

void InitPCB();			//PCB初始化函数
int ReadPCBFile();		//读进程流文件数据，存入PCB数组（队列）pcbs，并输出
void ReSetPCB();		//重置PCB完成标志、等待时间,以供另一个调度算法使用，并输出所读入的进程PCB数据
void FIFO();			//先进先出调度算法
void Priority();		//优先级调度算法
void RR();				//时间片轮转调度算法
void SPF();				//短进程优先调度算法
void Hint();			//显示实验提示信息函数
void Version();			//显示版权信息函数


void InitPCB()			//PCB初始化函数
{ 
	int i; 

	for(i=0;i<MAXPCB;i++)
	{ 
		strcpy(pcbs[i].sName,""); 
		pcbs[i].iStatus=-1; 
		pcbs[i].iRunTime=-1; 
		pcbs[i].iPriority=-1; 
		
		pcbs[i].iBeFinished=0; 
		pcbs[i].iWaitTime=0; 
	} //for(i=0;i<MAXPCB;i++)
	
	iPCBNum=0; 
} //void InitPCB()


int ReadPCBFile()	//读进程流文件数据，存入PCB数组（队列）pcbs，并输出
{ 
	FILE *fp; 
	int i; 
	char cHead;
	
	cout<<"	请输入要打开的进程流（文本）文件名（注意：包括路径名和后缀名）:  "; 
	cin>>sFileName; 

	if((fp=fopen(sFileName,"r"))==NULL)
	{ 
		cout<<"	错误：进程流文件 "<<sFileName<<" 打不开，请检查文件名和路径！！！"<<endl; 
		return -1;
	} 
	else	//if((fp=fopen(sFileName,"r"))==NULL)
	{
		cHead=fgetc(fp);
		while(cHead==' '||cHead=='\n'||cHead=='\t')	//过滤文件头部的空格、换行和TAB字符
		{
			cHead=fgetc(fp);
		}
		if(cHead==EOF)
		{
			printf("	错误：进程流文件：%s 为空！！！\n",sFileName );
			return -1;
		}
		else	//if(cHead==EOF)
		{
			fseek( fp, -1, SEEK_CUR); 
			while(!feof(fp))
			{ 
				fscanf(fp,"%s %d %d %d",pcbs[iPCBNum].sName,&pcbs[iPCBNum].iStatus,&pcbs[iPCBNum].iRunTime,&pcbs[iPCBNum ].iPriority); 
				iPCBNum++; 
			}	//while(!feof(fp))
			
			if(pcbs[iPCBNum-1].iStatus==-1)	  //去掉由于文件尾部的空格、换行和TAB字符导致的错误PCB计数
				{
				iPCBNum--;
				}  //if(pcbs[iPCBNum-1].iStatus==-1)

			//输出所读入的进程PCB数据
			cout<<endl<<"	从文件 "<<sFileName<<" 读入的进程数据："<<endl<<endl; 
			cout<<"	序号    进程名   进程状态  运行时间  优先数"<<endl; 
			for(i=0;i<iPCBNum;i++)
			{ 
				cout<<"	 "<<i+1<<"	  "<<pcbs[i].sName<<"	  "<<pcbs[i].iStatus<<"	  "<<pcbs[i].iRunTime<<"		  "<<pcbs[i].iPriority<<endl; 
			} 
			cout<<"	进程总数："<<iPCBNum<<endl; 

			return 0;
		}	//if(cHead==EOF)		
		 
	}	//if((fp=fopen(sFileName,"r"))==NULL)	

}// int ReadPCBFile()

 
void ReSetPCB()	//重置PCB完成标志、等待时间,以供另一个调度算法使用，并输出所读入的进程PCB数据
{ 
	int i; 
	
	//输出所读入的进程PCB数据 
	cout<<endl<<"---------------------------------------------------------------"<<endl; 
	cout<<endl<<"	从文件 "<<sFileName<<" 读入的进程数据："<<endl<<endl; 
	cout<<"	序号    进程名   进程状态  运行时间  优先数"<<endl; 
	for(i=0;i<iPCBNum;i++)
	{ 
		pcbs[i].iBeFinished=0; 
		pcbs[i].iWaitTime=0; 
		cout<<"	 "<<i+1<<"	  "<<pcbs[i].sName<<"	  "<<pcbs[i].iStatus<<"	  "<<pcbs[i].iRunTime<<"		  "<<pcbs[i].iPriority<<endl; 
	}
	cout<<"	进程总数："<<iPCBNum<<endl; 

} //void ReSetPCB()

 
void FIFO() //先进先出调度算法
{ 
	int i,j; 
	int iCurWaitTime=0;				//到调度时刻为止，所有末完成进程，已各自分别等待的时间

	//输出先进先出调度算法执行流 
	cout<<endl<<"---------------------------------------------------------------"<<endl; 
	cout<<"	先进先出调度算法执行流:"<<endl<<endl; 
	cout<<"	执行序号 进程名 运行时间 等待时间"<<endl; 

	iSumWaitTime=0; 

	for(i=0;i<iPCBNum;i++)
	{ 
		pcbs[i].iWaitTime = iCurWaitTime; 
		iCurWaitTime += pcbs[i].iRunTime; 

		cout<<"	 "<<i+1<<"	 "<<pcbs[i].sName<<"	 "<<pcbs[i].iRunTime<<"	 "<<pcbs[i].iWaitTime<<endl; 
		//输出信息摸拟进程运行

		iSumWaitTime+=pcbs[i].iWaitTime;	//累加总等待时间 		
	
	} 

	cout<<"	总调度次数:  "<<iPCBNum<<endl;
	cout<<"	总等待时间:  "<<iSumWaitTime<<endl;
	printf("	平均等待时间:  %.2f\n",(float)iSumWaitTime / (float)iPCBNum);
 
	cout<<endl<<"---------------------------------------------------------------"<<endl; 

} //void FIFO()

 
void SPF()	//短进程优先调度算法
{ 
	int i,j;
	int iCurMin=0;					//当前最短进程PCB，在数组（队列）pcbs中的下标 
	int iCurMinRunTime=999999999;	//当前最短进程运行时间
	int iCurWaitTime=0;				//到调度时刻为止，所有末完成进程，已各自分别等待的时间 

	int iSubScript[MAXPCB];			//存放按运行时间递增稳定排序后进程之下标的数组（队列）

	for(i=0;i<iPCBNum;i++)			//按进程运行时间递增稳定排序PCB，不调整数组（队列）pcbs，只将排序后的进程下标存放在数组（队列）iSubScript中。  （选择排序）
	{ 
		iCurMinRunTime=99999999; 
		for(j=0;j<iPCBNum;j++)
		{
			if((pcbs[j].iBeFinished==0)&&(pcbs[j].iRunTime<iCurMinRunTime))
			{ 
				iCurMin=j; 
				iCurMinRunTime=pcbs[j].iRunTime; 
			} 
		} //for(j=0;j<iPCBNum;j++)

		iSubScript[i]=iCurMin; 

		pcbs[iCurMin].iBeFinished=1; 

		pcbs[iCurMin].iWaitTime = iCurWaitTime; 
		iCurWaitTime += pcbs[iCurMin].iRunTime; 
	}	//for(i=0;i<iPCBNum;i++) 
	
	//输出短进程优先调度执行流 
	cout<<endl<<"---------------------------------------------------------------"<<endl; 
	cout<<"	短进程优先调度执行流:"<<endl<<endl; 
	cout<<"	执行序号 进程名 运行时间 等待时间"<<endl; 

	iSumWaitTime=0; 

	for(i=0;i<iPCBNum;i++)
	{
		cout<<"	 "<<i+1<<"	 "<<pcbs[iSubScript[i]].sName<<"	 "<<pcbs[iSubScript[i]].iRunTime<<"	 "<<pcbs[iSubScript[i]].iWaitTime<<endl; 
		//输出信息摸拟进程运行

		iSumWaitTime += pcbs[iSubScript[i]].iWaitTime;	//累加总等待时间 
	} 

	cout<<"	总调度次数:  "<<iPCBNum<<endl;
	cout<<"	总等待时间:  "<<iSumWaitTime<<endl;
	printf("	平均等待时间:  %.2f\n",(float)iSumWaitTime / (float)iPCBNum);

	cout<<endl<<"---------------------------------------------------------------"<<endl; 
	
} //void SPF ()


void HPF()	//优先级调度算法
{ 
	int i,j;
	int iCurMin=0;					//当前最低优先数（最高优先级）进程PCB，在数组（队列）pcbs中的下标
	int iCurMinPriority=999999999;	//当前最低优先数
	int iCurWaitTime=0;				//到调度时刻为止，所有末完成进程，已各自分别等待的时间

	int iSubScript[MAXPCB];			//存放按优先数递增稳定排序后进程之下标的数组（队列）

	for(i=0;i<iPCBNum;i++)			//按优先数递增稳定排序PCB，不调整数组（队列）pcbs，只将排序后的进程下标存放在数组（队列）iSubScript中。  （选择排序）
	{ 
		iCurMinPriority=99999999; 
		for(j=0;j<iPCBNum;j++)
		{
			if((pcbs[j].iBeFinished==0)&&(pcbs[j].iPriority<iCurMinPriority))
			{
				iCurMin=j; 
				iCurMinPriority=pcbs[j].iPriority; 
			} 
		} //for(j=0;j<iPCBNum;j++)

		iSubScript[i]=iCurMin; 

		pcbs[iCurMin].iBeFinished=1; 

		pcbs[iCurMin].iWaitTime = iCurWaitTime; 
		iCurWaitTime += pcbs[iCurMin].iRunTime; 
	}	//for(i=0;i<iPCBNum;i++) 
	
	//输出优先级调度执行流 
	cout<<endl<<"---------------------------------------------------------------"<<endl; 
	cout<<"	优先级调度执行流:"<<endl<<endl; 
	cout<<"	执行序号 进程名 优先数 运行时间 等待时间"<<endl; 

	iSumWaitTime=0; 

	for(i=0;i<iPCBNum;i++)
	{
		cout<<"	 "<<i+1<<"	"<<pcbs[iSubScript[i]].sName<<"	 "<<pcbs[iSubScript[i]].iPriority<<"	"<<pcbs[iSubScript[i]].iRunTime<<"	 "<<pcbs[iSubScript[i]].iWaitTime<<endl; 
		//输出信息摸拟进程运行

		iSumWaitTime += pcbs[iSubScript[i]].iWaitTime;	//累加总等待时间 
	} 

	cout<<"	总调度次数:  "<<iPCBNum<<endl;
	cout<<"	总等待时间:  "<<iSumWaitTime<<endl;
	printf("	平均等待时间:  %.2f\n",(float)iSumWaitTime / (float)iPCBNum);

	cout<<endl<<"---------------------------------------------------------------"<<endl; 
	
} //void HPF()

 
void RR()	//时间片轮转调度算法
{ 
	int i;
	int iNotAllEnded=1;		//轮转控制标志：不是所有进程，都已获得足够数量的时间片以运行完成，所以：需要继续下一次轮转，依次再给末完成进程1个时间片。
	int iNum=0;				//到目前为止末运行完成的进程数
	int iRound=0;			//轮转周期数
	int iSumTimeSlice=0;	//总时间片数
	float fSliceTime=10;	//时间片的长度（纳秒）
	
	cout<<endl<<"	请输入时间片的长度（纳秒）："<<endl<<"	";
	cin>>fSliceTime;

	cout<<endl<<"---------------------------------------------------------------"<<endl;
	cout<<"	时间片轮转调度执行流（时间片的长度为："<<fSliceTime<<"纳秒）:"<<endl; 

	while(iNotAllEnded==1)	//不是所有进程，都已获得足够数量的时间片以运行完成，所以：需要继续下一次轮转，依次再给末完成进程1个时间片。
	{
		iNotAllEnded=0; 
		iNum=0; 
		
		for(i=0;i<iPCBNum;i++)	//统计到目前为止末运行完成的进程数iNum
		{
			if(pcbs[i].iBeFinished==0)
			{ 
				iNum++;
				
			} //if(pcbs[i].iBeFinished==0)
		} //for(i=0;i<iPCBNum;i++)
		
		if(iNum>0)
		{
			iNotAllEnded=1;

			iRound++;	//轮转周期数自加
			cout<<endl<<"	第"<<iRound<<"轮：";

			for(i=0;i<iPCBNum;i++)
			{ 
				if(pcbs[i].iBeFinished==0)
				{
					cout<<pcbs[i].sName<<" ";	//输出进程名摸拟进程又运行了一个时间片		

					iSumTimeSlice++;	//累加总时间片数 

					if(pcbs[i].iRunTime <= (fSliceTime*(iRound) ) )
					//i进程累计获得的时间片能够使其运行完成
					{ 
						pcbs[i].iBeFinished=1; 

					} //if(pcbs[i].iRunTime<=fSliceTime*(iRound))

				}//if(pcbs[i].iBeFinished==0) 

			} //for(i=0;i<iPCBNum;i++)		

		} //if(iNum>0)

	} //while(iNotAllEnded==1)
	
	cout<<endl<<"	轮转周期数:"<<iRound<<"	总时间片数:"<<iSumTimeSlice<<endl;
	cout<<endl<<"---------------------------------------------------------------"<<endl; 

}//void RR() 

 
void Hint() //显示实验提示信息函数 
{ 
	cout<<endl; 
	
	cout<<"  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━			"<<endl;

	cout<<"  [实验概要]                                                                      "<<endl;
	cout<<"  ①、实验目的                                                                    "<<endl;
	cout<<"  a、进程调度是处理机管理的核心内容。观察、体会操作系统的进程调度方法，           "<<endl;
	cout<<"  并通过一个简单的进程调度算法模拟系统的实现，加深对进程控制块、进程队列、        "<<endl;
	cout<<"  进程调度算法，进程切换的理解，并体会和了解各种调度算法的具体实施办法。          "<<endl;
	cout<<"  b、提高实际动手编程能力，为日后从事软件开发工作打下坚实基础。                   "<<endl;
	cout<<"  ②、实验内容                                                                    "<<endl;
	cout<<"  a、设计进程控制块PCB表结构，模拟实现进程调度算法：FIFO，静态优先级调度，        "<<endl;
	cout<<"  时间片轮转调度，短进程优先调度算法，多级反馈队列调度（实现其中之一个以上）。    "<<endl;
	cout<<"  b、编写一个进程调度算法模拟系统。模拟系统只对被调度进程的PCB进行相应的模拟调度操作，被调度进程不需要实际代码和被处理数据。    "<<endl;
	cout<<"  c、由用户输入（可通过文件输入）进程名、进程状态、进程运行时间和进程优先数等数据。 "<<endl;
	cout<<"  ③、实验要求                                                                       "<<endl;
	cout<<"  a、使用模块化设计思想来设计；                                                        "<<endl;
	cout<<"  b、实验报告要求给出主函数和各个算法函数的流程图。                                     "<<endl;
	cout<<"  c、学生可按照自身条件，随意选择采用的算法，（例如：采用选择排序或者冒泡排序编写程序，实现短进程优先调度的算法）。 "<<endl;
	cout<<"  d、进程调度算法模拟系统只对被调度进程的PCB进行相应的模拟调度操作，被调度进程不需要实际代码和被处理数据。  "<<endl;
	cout<<"  ④、运行结果                                                                                     "<<endl;
	cout<<"  a、给出对被调度进程的PCB进行相应的模拟调度操作的结果。                                           "<<endl;
	cout<<"  ⑤、提示                                                                                         "<<endl;
	cout<<"  a、每个进程可有三个状态，并假设初始状态为就绪状态。                                              "<<endl;
	cout<<"  b、为了便于处理，程序中的进程运行时间以纳秒为单位计算。                                          "<<endl;
	cout<<"  c、各进程的优先数或轮转时间片长度以及进程需运行的时间的初始值均由用户给定。                      "<<endl;
	cout<<"  d、在优先级算法中，采用静态优先级。在时间片轮转算法中，采用可变时间片，由用户给定。              "<<endl;
	cout<<"  e、对于遇到运行时间或优先级相同的情况，采用FIFO策略解决。                                        "<<endl;
	cout<<"  f、输入：进程流文件（文本文件），其中存储的是一系列要执行的进程，每个进程包括至少四个数据项：    "<<endl;
	cout<<"     进程名、进程状态（1就绪 2等待 3运行）、所需时间、优先数（数字越小优先级越高）。               "<<endl;
	cout<<"  g、输出：进程执行流 等待时间 平均等待时间。                                                      "<<endl;
	cout<<"		 												                                            	"<<endl;
	cout<<"  一、本进程调度算法模拟系统包括:FIFO，短进程优先调度算法，优先级调度算法（静态优先级），时间片轮转调度算法。      "<<endl;
	cout<<"   VC++6.0调试通过  项目类型：Win32 Console Application。                                          "<<endl;
	cout<<"  输入：进程流文件（文本文件），其中存储的是一系列要执行的进程，每个进程包括四个数据项：           "<<endl;
	cout<<"   	进程名、进程状态（1就绪 2等待 3运行）、所需时间、优先数（数字越小优先级越高）                 "<<endl;
	cout<<"  输出：进程调度执行流、等待时间、平均等待时间等。                                                 "<<endl;
	cout<<"     VC++6.0调试通过   项目类型：Win32 Console Application	                	"<<endl;
	cout<<"		 												                        	"<<endl;
	cout<<"  二、 在WINDOWS中双击DEBUG目录中的EXE文件直接运行，可能没有显示结果窗口就关闭了， "<<endl;
	cout<<"     这不是程序错误，解决方法是：	                                         	"<<endl;
	cout<<"     1、“开始->程序->附件-命令提示符”,打开DOS命令窗口。                    	"<<endl;
	cout<<"     2、改变当前目录至EXE文件所在目录；                                      	"<<endl;
	cout<<"     （或者将EXE文件和测试用的文本文件一并复制到当前目录）。                    	"<<endl;
	cout<<"     3、输入EXE文件的完整名称（含后缀名）运行即可。为简化输入，可以重命名EXE文件。"<<endl;

	cout<<"  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━			"<<endl; 
	cout<<endl; 

} //void Hint() 


void Version()	//显示版权信息函数
{ 
	cout<<endl<<endl; 
	
	cout<<"	 ┏━━━━━━━━━━━━━━━━━━━━━━━┓"<<endl; 
	cout<<"	 ┃　　　　　进程调度算法模拟系统　 　 　　　　　┃"<<endl; 
	cout<<"	 ┠───────────────────────┨"<<endl; 
	cout<<"	 ┃　 　   　(c)All Right Reserved 　　    　　　┃"<<endl; 
	cout<<"	 ┃　　　　　　   LGY  赖国勇   　 　　　　　　　┃"<<endl; 
	cout<<"	 ┃　　　　　Version 2023 build 4   　　 　　　　┃"<<endl; 
	cout<<"	 ┗━━━━━━━━━━━━━━━━━━━━━━━┛"<<endl; 
	cout<<endl<<endl; 
} //void Version()


 
int main()		//主函数
{ 
	int iInput=0;	//用户输入的整数编号以选择算法 
	bool bGoOn;		//是否继续进程调度算法模拟演示的标志变量
	char sGoOn[1];	//用户输入的是否继续进程调度算法模拟演示的字符：y、Y、N、n

	Hint();			//显示实验提示信息函数
	Version();		//显示版权信息函数
	
	InitPCB();		//PCB初始化函数
	
	bGoOn= true;
	strcpy(sGoOn," ");	
		
	if(ReadPCBFile()==0)	//读进程流文件数据，存入PCB数组（队列）pcbs，并输出。 返回值：执行是否正常，0 正常
	{
		while (bGoOn)
		{
			cout<<endl<<"	请输入算法编号（1 OR 2 OR 3 OR 4）选择进程调度算法："<<endl<<endl;	
			cout<<"	1  先进先出调度算法"<<endl<<endl<<"	2  短进程优先调度算法"<<endl<<endl;
			cout<<"	3  优先级调度算法"<<endl<<endl<<"	4  时间片轮转调度算法"<<endl<<endl<<"	";

			cin>>iInput;		//从标准输入获取用户输入的整数以选择算法
			switch(iInput)
			{
			case 1:
				ReSetPCB();		//重置PCB完成标志、等待时间,以供另一个调度算法使用，并输出所读入的进程PCB数据
				FIFO();			//先进先出调度算法
				break;
				
			case 2:
				ReSetPCB();		
				SPF();			//短进程优先调度算法
				break;
				
			case 3:
				ReSetPCB();		
				HPF();			//优先级调度算法
				break;
				
			case 4:
				ReSetPCB();		
				RR();			//时间片轮转调度算法
				break;

			default:
				printf("\n	输入的算法编号错误！！！\n");	
				return 0;
				
			}	//switch(iInput)
			
			bGoOn= false;
			strcpy(sGoOn," ");
			
			cout<<endl<<"	要继续进行进程调度算法模拟演示吗？(Y/N)"<<endl<<"	";
			cin>>sGoOn;		
			bGoOn=((sGoOn[0]=='y')||(sGoOn[0]=='Y'));
						
		}//while bGoOn
	}
	else
	{
		printf("	读入进程流文件失败！！！\n\n");
	} //if(ReadPCBFile()==0)
}//void main()
