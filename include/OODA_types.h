

#define CMD_BUF_LENTH 5 //最多缓存的指令数量
#define CMD_MAX_LENTH_CHAR 8192 //每条指令最多的字节数
#define CMD_MAX_LENTH_WORDS 1024//每条指令最多的单词数
#define WORD_LENTH 31//每个单词最大长度、强烈建议不要改!
#define CMD_WORST_PRIO 1000
#define MISSION_MAX_NODES 5

#define OB_SUB_LIST_LENTH 5
#define OR_OPERATE_LIST_LENTH 20
#define DE_OPERATE_LIST_LENTH 20
#define AC_PUB_LIST_LENTH 5

#define OODA_EXE_INPUT_NUM_MAX 5
#define OODA_EXE_OUTPUT_NUM_MAX 5
#define OODA_EXE_REG_NUM_MAX 128
#define OODA_EXE_OR_LENTH_MAX 100
#define OODA_EXE_DE_LENTH_MAX 100



typedef enum Executor_Busy_Status{
	notbusy,
	busy
}executor_busy_status;

typedef enum Executor_Current_Status
{
	OB,
	OR,
	DE,
	AC
}executor_current_status;
typedef enum OODA_Reg_Type
{
	ooda_Str,
	ooda_Int,
	ooda_Float
}ooda_reg_type;

typedef union OODA_Reg_Value
{
	char srt[WORD_LENTH];
	float float_value;
	int int_value;
}ooda_reg_value;
typedef struct OODA_Reg
{
	char name[WORD_LENTH];
	ooda_reg_type type;
	ooda_reg_value value;
}ooda_reg;

typedef struct OB_SUB
{
	char sub_topic_name[WORD_LENTH];
	ooda_reg *target_reg;
}ob_sub;//单条订阅中间码的数据结构
typedef enum OP_OR
{
	plus,	//加
	minus,	//减
	times,	//乘
	devide,	//除

	or,		//逻辑或
	and,	//逻辑与
	not,	//非
	eq,		//等于
	neq,		//不等于
	ge,		//大于等于
	le,		//小于等于
	gt,		//大于
	lt		//小于
}op_or;//or阶段支持的操作码
typedef struct OR_OPERATE
{
	op_or OP;
	ooda_reg *rs1;
	ooda_reg *rs2;
	ooda_reg *rd;
}or_operate;//单条判断计算的数据结构


typedef enum OP_DE
{
	//条件成立则发布对应的消息
	de_eq,		//等于
	de_neq,		//不等于
	de_ge,		//大于等于
	de_le,		//小于等于
	de_gt,		//大于
	de_lt		//小于
}op_de;//de阶段支持的操作
typedef struct DE_COMP
{
	op_de OP;
	ooda_reg *rs1;
	ooda_reg *rs2;

}de_comp;//单条决策比较的数据结构

typedef struct AC_PUB
{
	char pub_topic_name[WORD_LENTH];
	ooda_reg *source_reg;
}ac_pub;//单条订阅中间码的数据结构





typedef enum Cmd_Status
{
	blank,
	receiveing,
	received,
	worded,
	working,
	done
}cmd_status;//用于保存指令buf中各指令的状态

typedef struct OODA_Symble
{
//与执行器中reg对应的部分
	char name[WORD_LENTH];
	ooda_reg_type type;
	ooda_reg_value value;
	//不对应
	int initiallised;//是否有初始值
}ooda_symble;

//new added struct to store the cmdList information
typedef struct Node_info
{
    char name[WORD_LENTH];
}node_info;



typedef struct Cmd_Info
{

	cmd_status my_status;//任务状态	blank,	receiveing,	received,	worded,	working,	done
//由串口中断ooda_data_in_ISR初始化的内容
	unsigned int cmd_lenth_in_in_char;			//当状态为receiveing的时候为已经接受的长度，之后的状态为总的字符长度
	char cmd_char[CMD_MAX_LENTH_CHAR];

//由文法解析产生的内容
	unsigned int priority;//任务优先级,魔数CMD_WORST_PRIO,当优先级大于CMD_WORST_PRIO任务无法执行

	char needed_node_name[MISSION_MAX_NODES][WORD_LENTH];

	unsigned int symblelist_lenth;								//symblelist 长度，为1则 symblelist[0]有效。。。。
	ooda_symble symblelist[OODA_EXE_REG_NUM_MAX];

    //new added
    unsigned int needed_nodes_cmp_lenth;
    node_info needed_nodes_cmp[MISSION_MAX_NODES]; //store component information


	unsigned int this_OB_topics_lenth;							//this_OB_topics长度，为1则 this_OB_topics[0]有效。。。。
	ob_sub this_OB_topics[OODA_EXE_INPUT_NUM_MAX];			//执行器的输入(OB阶段)

	unsigned int this_AC_topics_lenth;
	ac_pub this_AC_topics[OODA_EXE_OUTPUT_NUM_MAX];		//执行器的输出(AC阶段)

	unsigned int this_OR_cmd_list_lenth;
	or_operate this_OR_cmd_list[OODA_EXE_OR_LENTH_MAX];	//ooda执行器在OR阶段执行的中间码

	unsigned int this_DE_cmd_list_lenth;
	de_comp this_DE_cmd_list[OODA_EXE_OR_LENTH_MAX];	//ooda执行器在DE阶段执行的中间码

}cmd_info;


//top level of ooda data struct
typedef struct Cmd_List
{
	cmd_info *current_reciveing_cmd;//正在接收的指令指针
	cmd_info *current_runing_cmd;
	cmd_info ALL_CMDS[CMD_BUF_LENTH];
}cmd_list;




//top level of one single command struct
typedef struct Ooda_Executor{
	executor_busy_status ooda_busy;
	unsigned int priority;										//当前执行指令组的优先级
	executor_current_status this_status;							//ooda 执行器执行状态OB/OR/DE/AC
	ooda_reg this_ooda_regs[OODA_EXE_REG_NUM_MAX];

	cmd_info *runing_cmd;

	unsigned int OB_PC;
	unsigned int OR_PC;
	unsigned int DE_PC;
	unsigned int AC_PC;


}ooda_executor;

