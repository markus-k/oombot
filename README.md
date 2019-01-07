# oombot - let web crawlers run out of memory

Originally inspired by [this tweet from @geofurb](https://twitter.com/geofurb/status/1080264236230733824).

A CGI program to send an infinite stream of data to bots crawling your webserver.

## Usage
Compile the C-program using `make` and copy `oombot`, `robots_txt`, `robots_txt2` and `sitemap_xml` to the cgi-bin of your cgi-enabled webserver.

For example:
```
make
cp oombot robots_txt robots_txt2 sitemap_xml /var/www/html/cgi-bin/
```

Then use a reverse proxy or aliasing to point your `/robots.txt` or `/sitemap.xml` to this path.

For example in a nginx server configuration:
```
server {
  ...
  
  location /robots.txt {
    proxy_pass http://some-host/cgi-bin/robots_txt;
  }
}
```

Be aware that some bots can cause multiple Terabytes of traffic on your webserver if you aren't paying attention, so be careful with metered traffic such as Amazon EC2.
