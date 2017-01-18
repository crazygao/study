
# From http://agiliq.com/blog/2013/07/basics-wsgi/
from wsgiref.simple_server import make_server

# callable = Web Application
def application(environ, start_response):
    path = environ.get('PATH_INFO')
    if path == '/':
        response_body = "Index"
    else:
        response_body = "Hello"
    status = "200 OK"
    response_headers = [("Content-Length", str(len(response_body)))]
    start_response(status, response_headers)
    return [response_body]

# make_server python function, create a WSGI compliant server
# httpd is Web Server
#httpd = make_server('127.0.0.1', 8051, application)
#httpd.serve_forever()
