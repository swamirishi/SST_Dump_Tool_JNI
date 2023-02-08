Steps to build:
1) To create header file
```
javah -cp src/main/java -d src/main/native SSTDumpTool
``` 
2) To Build: 
```
mkdir -p build
cd build
cmake ../
make
```

3) Build Jar:

```
mvn clean install
```

4) Run:
```
 java -Djava.library.path=./build -cp target/dummyrocks-1.0-SNAPSHOT.jar SSTDumpTool
```