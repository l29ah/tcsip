#ifndef AJITTER
#define AJITTER

#define AJD 32

typedef void(aj_h)(void*arg);

typedef struct
ajitter {
	int used;
	char *buffer;
	double time[AJD];
	double last;
	int csize;
	char *out_buffer;
	int out_have;
	aj_h *handler;
	void *handler_arg;
} ajitter;

typedef struct {
	int left;
	int off;
	int idx;
	char *data;
} ajitter_packet;

ajitter * ajitter_init(int chunk_size);
ajitter_packet * ajitter_put_ptr(ajitter *aj);
ajitter_packet *ajitter_get_ptr(ajitter *aj);
void ajitter_put_done(ajitter *aj, int idx, double time);

void ajitter_get_done(ajitter *aj, int idx);

void ajitter_destroy(ajitter *aj);
char *ajitter_get_chunk(ajitter *aj, int size, int *ts);
int ajitter_copy_chunk(ajitter *aj, int size, char* ob, int *ts);
void ajitter_set_handler(ajitter *aj, aj_h handler, void *arg);

#endif
