#include "fcgiapp.h"

int main(void) {
  if (FCGX_Init()) {
    return 1;
  }

  FCGX_Request request;
  FCGX_InitRequest(&request, 0, 0);

  while (FCGX_Accept_r(&request) == 0) {
    FCGX_FPrintF(request.out, "Content-type: text/html\r\n");
    FCGX_FPrintF(request.out, "\n");
    FCGX_FPrintF(request.out, "<html>\n");
    FCGX_FPrintF(request.out, "\r<head>\n");
    FCGX_FPrintF(request.out, "\r\r<title>Hello World! </title>\n");
    FCGX_FPrintF(request.out, "\r</head>\n");
    FCGX_FPrintF(request.out, "\r<body>\n");
    FCGX_FPrintF(request.out, "\r\r<h1><center>Hello World</center></h1>\n");
    FCGX_FPrintF(request.out, "\r</body>\n");
    FCGX_FPrintF(request.out, "</html>\n");

    FCGX_Finish_r(&request);
  }

  return 0;
}
