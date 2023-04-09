# curl-url-response-checker-c

<p> A useful C script that reads a text file line by line and executes a curl command to get the HTTP/HTTPS response code. </p>

<br>

<h2> <li> Script Usage: </li> </h2>

During the [NGX_HTTP_CONTENT_PHASE](http://nginx.org/en/docs/dev/development_guide.html) phase of my scenario, the curl command is needed to iterate over each URL and apply it; To test the Nginx web-server by sending HTTP/HTTPS requests and examining the responses. That script has made the testing journey a whole lot easier; Eliminating the need for curl manual testing.

<br>

<h2> <li> Example: </li> </h2>

<br>

 <p align="center"> <img width="500" alt="image" src="https://user-images.githubusercontent.com/59771760/230767227-3c128ce1-1c42-4c55-a470-f362c3b51d01.png">
 </p>
 
 <br>

> `C_scripts`: A folder where 'C' language scripts being saved

> `CurlChecker`: '.c' file which contains the code segment


---
