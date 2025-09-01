int logic(char *data,int *turn,int *enp);

int wturn(int *pos,char piece ,char *data);
int bturn(int *pos,char piece ,char *data);

int wrook(char *data,int *pos);
int brook(char *data,int *pos);
int rpath(char *data,int *pos);

int wpawn(char *data,int *pos);
int bpawn(char *data,int *pos);

int wking(char *data,int *pos);
int bking(char *data,int *pos);

int bpath(char *data,int *pos);
int wbishoop(char *data,int *pos);
int bbishoop(char *data ,int *pos);

int rqueen(char *data,int *pos);
int wqueen(char *data,int *pos);
int bqueen(char *data,int *pos);

int wknight(char *data,int *pos);
int bknight(char *data,int *pos);
