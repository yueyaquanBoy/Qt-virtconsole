#ifndef CONNECT_H
#define CONNECT_H


/* dummy error function to suppress virDefaultErrorFunc */

int main(int argc, char *argv[])
{
virConnectPtr conn;
virError err;
virSetErrorFunc(NULL, customErrorFunc);
conn = virConnectOpen("qemu:///system");
if (conn == NULL) {
fprintf(stderr, "Failed to open connection to qemu:///system\n");
return 1;
}
if (virConnectGetVersion(conn, NULL) < 0) {
virCopyLastError(&err);
fprintf(stderr, "virConnectGetVersion failed: %s\n", err.message);
virResetError(&err);
}
virConnectClose(conn);
retu

#endif // CONNECT_H
