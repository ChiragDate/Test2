/*
============================================================================
Name : 2.c
Author : Chirag Date 
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.
Date: 25th Aug, 2024.
============================================================================
*/

void main(){
  while(1);
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/2$ gcc 2.c -o 2.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/2$ ./2.out&
[1] 6308
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/2$ ^C
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/2$ cd /proc
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/proc$ ls 
1     1688  1970  227   40    5597  631   90             kpagecgroup
10    1697  1972  228   4067  56    6321  909            kpagecount
100   1699  1974  23    41    5600  639   91             kpageflags
1002  17    1975  2329  4279  5601  64    92             loadavg
108   1710  1978  2388  428   5602  640   94             locks
11    1716  198   2410  43    5627  647   97             mdstat
110   1718  1980  2426  4314  57    65    972            meminfo
111   1742  1986  2440  4378  574   660   98             misc
116   1743  1989  2451  44    575   668   99             modules
1183  1753  199   25    447   576   67    acpi           mounts
12    1817  1992  2514  45    5776  69    asound         mtd
13    1824  1995  26    4578  5793  698   bootconfig     mtrr
14    1835  2     27    46    58    70    buddyinfo      net
142   1841  20    2701  461   582   703   bus            pagetypeinfo
1491  1846  200   271   462   585   71    cgroups        partitions
15    1857  201   2717  463   588   718   cmdline        pressure
1505  1861  2029  2758  464   59    725   consoles       schedstat
1508  1863  203   28    469   598   73    cpuinfo        scsi
1557  1874  2034  2827  47    6     74    crypto         self
156   1881  204   29    4758  60    747   devices        slabinfo
1564  1886  205   297   49    602   75    diskstats      softirqs
1565  1898  206   2975  5     6056  76    dma            stat
157   19    2080  2982  50    61    77    driver         swaps
1571  1911  2082  3     5000  613   78    dynamic_debug  sys
1574  192   21    305   51    615   79    execdomains    sysrq-trigger
158   1929  2102  31    5120  6150  8     fb             sysvipc
1584  1930  2123  3127  52    6191  80    filesystems    thread-self
1587  194   2135  32    53    62    81    fs             timer_list
1588  1944  2141  33    530   622   82    interrupts     tty
159   1952  2150  34    5305  6227  83    iomem          uptime
16    1953  2164  3434  531   625   84    ioports        version
160   1956  2192  35    5317  627   85    irq            version_signature
1607  1957  22    37    532   6272  86    kallsyms       vmallocinfo
1611  196   2214  371   5322  6291  87    kcore          vmstat
1618  1960  2223  38    5434  63    88    keys           zoneinfo
1643  1966  2250  39    55    6307  89    key-users
1647  197   2256  4     5596  6308  9     kmsg

============================================================================
*/
