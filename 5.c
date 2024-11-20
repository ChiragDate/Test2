/*
============================================================================
Name : 5.c
Author : Chirag Date 
Description :Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 25th Aug, 2024.
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     

void main()
{
    while (1)
    {
        creat("file1", O_CREAT);
        creat("file2", O_CREAT);
        creat("file3", O_CREAT);
        creat("file4", O_CREAT);
        creat("file5", O_CREAT);
    }
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/5$ gcc 5.c -o 5.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/5$ ./5.out &
[1] 5369
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/5$ cd /proc
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/proc$ ls
1     163   1911  2065  305   467   58   73    asound         mdstat
10    164   1912  2067  31    468   583  74    bootconfig     meminfo
100   165   1914  207   32    469   586  747   buddyinfo      misc
1059  166   1915  2082  3251  47    589  75    bus            modules
108   1661  1919  2099  33    470   59   76    cgroups        mounts
11    1662  192   21    34    4839  6    77    cmdline        mtd
110   1664  1922  2103  35    49    602  78    consoles       mtrr
111   167   1924  2109  36    4900  609  79    cpuinfo        net
116   1674  1925  2120  3654  4992  61   8     crypto         pagetypeinfo
1191  1680  1927  2152  3670  5     612  80    devices        partitions
12    1682  1931  2169  3673  50    616  81    diskstats      pressure
13    17    1934  2188  3696  51    62   82    dma            schedstat
139   1706  1936  22    37    52    626  83    driver         scsi
14    1709  1937  2206  371   5261  628  84    dynamic_debug  self
15    1716  194   2258  372   5281  629  85    execdomains    slabinfo
1509  1779  1948  2277  38    53    63   86    fb             softirqs
1512  1786  1950  228   387   530   634  87    filesystems    stat
1515  1796  1951  229   39    531   64   88    fs             swaps
1522  1802  1952  23    4     532   643  89    interrupts     sys
1528  1803  1957  2343  40    5329  644  9     iomem          sysrq-trigger
1529  1818  197   2377  4041  5336  65   90    ioports        sysvipc
1535  1819  198   2391  41    5355  654  907   irq            thread-self
1538  1820  2     2403  4161  5368  66   91    kallsyms       timer_list
1543  1830  20    25    42    5369  67   92    kcore          tty
1551  1838  200   2528  43    5374  69   93    keys           uptime
1552  1843  201   26    4343  55    696  94    key-users      version
1572  1855  202   27    44    56    70   96    kmsg           version_signature
1576  1867  203   271   443   57    71   97    kpagecgroup    vmallocinfo
1583  1886  204   28    448   573   711  976   kpagecount     vmstat
16    1887  205   29    45    575   72   98    kpageflags     zoneinfo
1607  19    206   3     46    576   721  99    loadavg
1611  1903  2064  30    463   577   722  acpi  locks


============================================================================
*/
