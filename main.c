#include "httpd.h"

int main(int c, char **v)
{
  serve_forever("8080");
  return 0;
}

void route()
{
  ROUTE_START()

  // for get test
  ROUTE_GET("/")
  {
    printf("HTTP/1.1 200 OK\r\n\r\n");
    printf("Hello! You are using %s", request_header("User-Agent"));
  }

  // for post test
  ROUTE_POST("/")
  {
    printf("HTTP/1.1 200 OK\r\n\r\n");
    printf("Wow, seems that you POSTed %d bytes. \r\n", payload_size);
    printf("Fetch the data using `payload` variable.");
  }

  ROUTE_GET("/header")
  {
    printf("HTTP/1.1 200 OK\r\n\r\n");
    printf("List of request headers:\r\n\r\n");

    header_t *h = request_headers();

    while (h->name)
    {
      printf("%s: %s\n", h->name, h->value);
      h++;
    }
  }

  ROUTE_GET("/position")
  {
    printf("HTTP/1.1 200 OK\r\n");
    // printf("server: robot\r\n\r\n");
    printf("Content-Type: application/json\r\n\r\n");
    printf("{ \"x\" : 128, \"y\" : 256}");
  }

  ROUTE_END()
}
