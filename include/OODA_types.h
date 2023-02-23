

#define CMD_BUF_LENTH 5 //��໺���ָ������
#define CMD_MAX_LENTH_CHAR 8192 //ÿ��ָ�������ֽ���
#define CMD_MAX_LENTH_WORDS 1024//ÿ��ָ�����ĵ�����
#define WORD_LENTH 31//ÿ��������󳤶ȡ�ǿ�ҽ��鲻Ҫ��!
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
}ob_sub;//���������м�������ݽṹ
typedef enum OP_OR
{
	plus,	//��
	minus,	//��
	times,	//��
	devide,	//��

	or,		//�߼���
	and,	//�߼���
	not,	//��
	eq,		//����
	neq,		//������
	ge,		//���ڵ���
	le,		//С�ڵ���
	gt,		//����
	lt		//С��
}op_or;//or�׶�֧�ֵĲ�����
typedef struct OR_OPERATE
{
	op_or OP;
	ooda_reg *rs1;
	ooda_reg *rs2;
	ooda_reg *rd;
}or_operate;//�����жϼ�������ݽṹ


typedef enum OP_DE
{
	//���������򷢲���Ӧ����Ϣ
	de_eq,		//����
	de_neq,		//������
	de_ge,		//���ڵ���
	de_le,		//С�ڵ���
	de_gt,		//����
	de_lt		//С��
}op_de;//de�׶�֧�ֵĲ���
typedef struct DE_COMP
{
	op_de OP;
	ooda_reg *rs1;
	ooda_reg *rs2;

}de_comp;//�������߱Ƚϵ����ݽṹ

typedef struct AC_PUB
{
	char pub_topic_name[WORD_LENTH];
	ooda_reg *source_reg;
}ac_pub;//���������м�������ݽṹ





typedef enum Cmd_Status
{
	blank,
	receiveing,
	received,
	worded,
	working,
	done
}cmd_status;//���ڱ���ָ��buf�и�ָ���״̬

typedef struct OODA_Symble
{
//��ִ������reg��Ӧ�Ĳ���
	char name[WORD_LENTH];
	ooda_reg_type type;
	ooda_reg_value value;
	//����Ӧ
	int initiallised;//�Ƿ��г�ʼֵ
}ooda_symble;

//new added struct to store the cmdList information
typedef struct Node_info
{
    char name[WORD_LENTH];
}node_info;



typedef struct Cmd_Info
{

	cmd_status my_status;//����״̬	blank,	receiveing,	received,	worded,	working,	done
//�ɴ����ж�ooda_data_in_ISR��ʼ��������
	unsigned int cmd_lenth_in_in_char;			//��״̬Ϊreceiveing��ʱ��Ϊ�Ѿ����ܵĳ��ȣ�֮���״̬Ϊ�ܵ��ַ�����
	char cmd_char[CMD_MAX_LENTH_CHAR];

//���ķ���������������
	unsigned int priority;//�������ȼ�,ħ��CMD_WORST_PRIO,�����ȼ�����CMD_WORST_PRIO�����޷�ִ��

	char needed_node_name[MISSION_MAX_NODES][WORD_LENTH];

	unsigned int symblelist_lenth;								//symblelist ���ȣ�Ϊ1�� symblelist[0]��Ч��������
	ooda_symble symblelist[OODA_EXE_REG_NUM_MAX];

    //new added
    unsigned int needed_nodes_cmp_lenth;
    node_info needed_nodes_cmp[MISSION_MAX_NODES]; //store component information


	unsigned int this_OB_topics_lenth;							//this_OB_topics���ȣ�Ϊ1�� this_OB_topics[0]��Ч��������
	ob_sub this_OB_topics[OODA_EXE_INPUT_NUM_MAX];			//ִ����������(OB�׶�)

	unsigned int this_AC_topics_lenth;
	ac_pub this_AC_topics[OODA_EXE_OUTPUT_NUM_MAX];		//ִ���������(AC�׶�)

	unsigned int this_OR_cmd_list_lenth;
	or_operate this_OR_cmd_list[OODA_EXE_OR_LENTH_MAX];	//oodaִ������OR�׶�ִ�е��м���

	unsigned int this_DE_cmd_list_lenth;
	de_comp this_DE_cmd_list[OODA_EXE_OR_LENTH_MAX];	//oodaִ������DE�׶�ִ�е��м���

}cmd_info;


//top level of ooda data struct
typedef struct Cmd_List
{
	cmd_info *current_reciveing_cmd;//���ڽ��յ�ָ��ָ��
	cmd_info *current_runing_cmd;
	cmd_info ALL_CMDS[CMD_BUF_LENTH];
}cmd_list;




//top level of one single command struct
typedef struct Ooda_Executor{
	executor_busy_status ooda_busy;
	unsigned int priority;										//��ǰִ��ָ��������ȼ�
	executor_current_status this_status;							//ooda ִ����ִ��״̬OB/OR/DE/AC
	ooda_reg this_ooda_regs[OODA_EXE_REG_NUM_MAX];

	cmd_info *runing_cmd;

	unsigned int OB_PC;
	unsigned int OR_PC;
	unsigned int DE_PC;
	unsigned int AC_PC;


}ooda_executor;

