# Learn Linux Shell Again

Following the [hackerrank tutorial](https://www.hackerrank.com/domains/shell).

Although this is a `bash` tutorial, try to 
stick to something minimal, such as `dash` so that my code 
is universal, runs fast, and more POSIX compliant. Thanks to Luke Smith. `#noBashism`

## template

For practicing, use,
```dash
#!/bin/dash

echo "hello there";
```

But in actual usages, we don't know which shell is in use (ie, dash, mksh, etc), hence in those cases, use 


```bash 
#!/bin/sh

echo "hello there";
```
