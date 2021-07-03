#  Under Construction ...

# System Management Bus(SMBus)

## System Management Bus(SMBus): Thermal Sensor

```
$author:   Jin-Wen (Ed) Lai
$date:     Mar. 2018
$revised:  Jun. 2018
$Keywords:
```

An exercise of fetching the values of Thermal Sensors from CPU.

## Content

* [Requirements](#requirements)
* [Command Line Interface](#command-line-interface)
* [Programming](#programming)
* [Running](#running)
* [Result](#result) 
* [Observation](#observation)
* [Analysis](#analysis)
* [Conclusion](#conclusion)
* [Advanced](#advanced)
* [Reference](#reference)
* [Appendix](#appendix)

## Requirements

### Ubuntu 16.04

- SMBus `apt install lm-sensors`

## Command Line Interface

- Confirm the OS version, `18.04`
  
  ``` sh
  $ sudo cat /etc/os-release
  NAME="Ubuntu"
  VERSION="18.04 LTS (Bionic Beaver)"
  ID=ubuntu
  ID_LIKE=debian
  PRETTY_NAME="Ubuntu 18.04 LTS"
  VERSION_ID="18.04"
  HOME_URL="https://www.ubuntu.com/"
  SUPPORT_URL="https://help.ubuntu.com/"
  BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
  PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
  VERSION_CODENAME=bionic
  UBUNTU_CODENAME=bionic
  ```

- Confirm the Linux Kernel version `4.15.0`
  
  ``` sh
  $ sudo uname -a
  Linux sdr 4.15.0-23-generic #25-Ubuntu SMP Wed May 23 18:02:16 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux
  ```

- Installation for `lm_sensors`
  
  ``` sh
  $ sudo apt install lm-sensors
  ```

- Running configuration for `lm_sensors`

  ``` sh
  $ sudo sensors-detect
  # sensors-detect revision 6284 (2015-05-31 14:00:33 +0200)
  # Board: ASUSTeK COMPUTER INC. PRIME Z270M-PLUS
  # Kernel: 4.4.0-128-generic x86_64
  # Processor: Intel(R) Core(TM) i7-7700 CPU @ 3.60GHz (6/158/9)
  
  This program will help you determine which kernel modules you need
  to load to use lm_sensors most effectively. It is generally safe
  and recommended to accept the default answers to all questions,
  unless you know what you're doing.
  
  Some south bridges, CPUs or memory controllers contain embedded sensors.
  Do you want to scan for them? This is totally safe. (YES/no): YES
  Module cpuid loaded successfully.
  Silicon Integrated Systems SIS5595...                       No
  VIA VT82C686 Integrated Sensors...                          No
  VIA VT8231 Integrated Sensors...                            No
  AMD K8 thermal sensors...                                   No
  AMD Family 10h thermal sensors...                           No
  AMD Family 11h thermal sensors...                           No
  AMD Family 12h and 14h thermal sensors...                   No
  AMD Family 15h thermal sensors...                           No
  AMD Family 16h thermal sensors...                           No
  AMD Family 15h power sensors...                             No
  AMD Family 16h power sensors...                             No
  Intel digital thermal sensor...                             Success!
      (driver `coretemp')
  Intel AMB FB-DIMM thermal sensor...                         No
  Intel 5500/5520/X58 thermal sensor...                       No
  VIA C7 thermal sensor...                                    No
  VIA Nano thermal sensor...                                  No
  
  Some Super I/O chips contain embedded sensors. We have to write to
  standard I/O ports to probe them. This is usually safe.
  Do you want to scan for Super I/O sensors? (YES/no): YES
  Probing for Super-I/O at 0x2e/0x2f
  Trying family `National Semiconductor/ITE'...               No
  Trying family `SMSC'...                                     No
  Trying family `VIA/Winbond/Nuvoton/Fintek'...               Yes
  Found unknown chip with ID 0xd121
      (logical device B has address 0x290, could be sensors)
  Probing for Super-I/O at 0x4e/0x4f
  Trying family `National Semiconductor/ITE'...               No
  Trying family `SMSC'...                                     No
  Trying family `VIA/Winbond/Nuvoton/Fintek'...               No
  Trying family `ITE'...                                      No
  
  Some systems (mainly servers) implement IPMI, a set of common interfaces
  through which system health data may be retrieved, amongst other things.
  We first try to get the information from SMBIOS. If we don't find it
  there, we have to read from arbitrary I/O ports to probe for such
  interfaces. This is normally safe. Do you want to scan for IPMI
  interfaces? (YES/no): YES
  Probing for `IPMI BMC KCS' at 0xca0...                      No
  Probing for `IPMI BMC SMIC' at 0xca8...                     No
  
  Some hardware monitoring chips are accessible through the ISA I/O ports.
  We have to write to arbitrary I/O ports to probe them. This is usually
  safe though. Yes, you do have ISA I/O ports even if you do not have any
  ISA slots! Do you want to scan the ISA I/O ports? (YES/no): YES
  Probing for `National Semiconductor LM78' at 0x290...       No
  Probing for `National Semiconductor LM79' at 0x290...       No
  Probing for `Winbond W83781D' at 0x290...                   No
  Probing for `Winbond W83782D' at 0x290...                   No
  
  Lastly, we can probe the I2C/SMBus adapters for connected hardware
  monitoring devices. This is the most risky part, and while it works
  reasonably well on most systems, it has been reported to cause trouble
  on some systems.
  Do you want to probe the I2C/SMBus adapters now? (YES/no): YES
  Found unknown SMBus adapter 8086:a2a3 at 0000:00:1f.4.
  Sorry, no supported PCI bus adapters found.
  
  Next adapter: i915 gmbus dpc (i2c-0)
  Do you want to scan it? (yes/NO/selectively): yes
  
  Next adapter: i915 gmbus dpb (i2c-1)
  Do you want to scan it? (yes/NO/selectively): yes
  
  Next adapter: i915 gmbus dpd (i2c-2)
  Do you want to scan it? (yes/NO/selectively): yes
  
  Next adapter: DPDDC-E (i2c-3)
  Do you want to scan it? (yes/NO/selectively): yes
  
  
  Now follows a summary of the probes I have just done.
  Just press ENTER to continue:
  
  Driver `coretemp':
    * Chip `Intel digital thermal sensor' (confidence: 9)
  
  To load everything that is needed, add this to /etc/modules:
  #----cut here----
  # Chip drivers
  coretemp
  #----cut here----
  If you have some drivers built into your kernel, the list above will
  contain too many modules. Skip the appropriate ones!
  
  Do you want to add these lines automatically to /etc/modules? (yes/NO)yes
  Successful!
  
  Monitoring programs won't work until the needed modules are
  loaded. You may want to run '/etc/init.d/kmod start'
  to load them.
  
  Unloading cpuid... OK
  ```

- Fetching CPU Temperature by `sensors`. But we only got 4 results of Temperatures of Temperature even this is 8-core CPU.

  ```
  asus-isa-0000
  Adapter: ISA adapter
  cpu_fan:        0 RPM

  acpitz-virtual-0
  Adapter: Virtual device
  temp1:        +27.8°C  (crit = +119.0°C)
  temp2:        +29.8°C  (crit = +119.0°C)

  coretemp-isa-0000
  Adapter: ISA adapter
  Package id 0:  +33.0°C  (high = +80.0°C, crit = +100.0°C)
  Core 0:        +31.0°C  (high = +80.0°C, crit = +100.0°C)
  Core 1:        +33.0°C  (high = +80.0°C, crit = +100.0°C)
  Core 2:        +32.0°C  (high = +80.0°C, crit = +100.0°C)
  Core 3:        +33.0°C  (high = +80.0°C, crit = +100.0°C)
  ```

- Workaround
  - Use `the highest temperatures` in all of the results. It's `+33.0°C` in above case.


## Programming

- Python
  - n/a

## Running

- n/a

## Result

- n/a

## Observation

- n/a

## Analysis

- n/a

## Conclusion

- n/a

## Advanced

- We can consider to grab below information also    
  - Temperature (done)
  - Fan Speed

- We can consider to grab CPU Temperature by `ACPI` also
  - ACPI(Advanced Configuration & Power Interface) 

- We can consider to grab CPU Temperature in `Windows 7` also
  - CPUZ 

## Reference

## Appendix

- The CPU info of `i7-7700`
  ```
  $ sudo cat /proc/cpuinfo
  processor       : 0
  vendor_id       : GenuineIntel
  cpu family      : 6
  model           : 158
  model name      : Intel(R) Core(TM) i7-7700 CPU @ 3.60GHz
  stepping        : 9
  microcode       : 0x84
  cpu MHz         : 4194.140
  cache size      : 8192 KB
  physical id     : 0
  siblings        : 8
  core id         : 0
  cpu cores       : 4
  apicid          : 0
  initial apicid  : 0
  fpu             : yes
  fpu_exception   : yes
  cpuid level     : 22
  wp              : yes
  flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch invpcid_single intel_pt ibrs ibpb stibp kaiser tpr_shadow vnmi flexpriority ept vpid fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpcid rtm mpx rdseed adx smap clflushopt xsaveopt xsavec xgetbv1 dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp
  bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass
  bogomips        : 7199.89
  clflush size    : 64
  cache_alignment : 64
  address sizes   : 39 bits physical, 48 bits virtual
  power management:
  
  processor       : 1
  vendor_id       : GenuineIntel
  cpu family      : 6
  model           : 158
  model name      : Intel(R) Core(TM) i7-7700 CPU @ 3.60GHz
  stepping        : 9
  microcode       : 0x84
  cpu MHz         : 4169.250
  cache size      : 8192 KB
  physical id     : 0
  siblings        : 8
  core id         : 1
  cpu cores       : 4
  apicid          : 2
  initial apicid  : 2
  fpu             : yes
  fpu_exception   : yes
  cpuid level     : 22
  wp              : yes
  flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch invpcid_single intel_pt ibrs ibpb stibp kaiser tpr_shadow vnmi flexpriority ept vpid fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpcid rtm mpx rdseed adx smap clflushopt xsaveopt xsavec xgetbv1 dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp
  bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass
  bogomips        : 7199.89
  clflush size    : 64
  cache_alignment : 64
  address sizes   : 39 bits physical, 48 bits virtual
  power management:
  
  processor       : 2
  vendor_id       : GenuineIntel
  cpu family      : 6
  model           : 158
  model name      : Intel(R) Core(TM) i7-7700 CPU @ 3.60GHz
  stepping        : 9
  microcode       : 0x84
  cpu MHz         : 4178.812
  cache size      : 8192 KB
  physical id     : 0
  siblings        : 8
  core id         : 2
  cpu cores       : 4
  apicid          : 4
  initial apicid  : 4
  fpu             : yes
  fpu_exception   : yes
  cpuid level     : 22
  wp              : yes
  flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch invpcid_single intel_pt ibrs ibpb stibp kaiser tpr_shadow vnmi flexpriority ept vpid fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpcid rtm mpx rdseed adx smap clflushopt xsaveopt xsavec xgetbv1 dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp
  bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass
  bogomips        : 7199.89
  clflush size    : 64
  cache_alignment : 64
  address sizes   : 39 bits physical, 48 bits virtual
  power management:
  
  processor       : 3
  vendor_id       : GenuineIntel
  cpu family      : 6
  model           : 158
  model name      : Intel(R) Core(TM) i7-7700 CPU @ 3.60GHz
  stepping        : 9
  microcode       : 0x84
  cpu MHz         : 4122.000
  cache size      : 8192 KB
  physical id     : 0
  siblings        : 8
  core id         : 3
  cpu cores       : 4
  apicid          : 6
  initial apicid  : 6
  fpu             : yes
  fpu_exception   : yes
  cpuid level     : 22
  wp              : yes
  flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch invpcid_single intel_pt ibrs ibpb stibp kaiser tpr_shadow vnmi flexpriority ept vpid fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpcid rtm mpx rdseed adx smap clflushopt xsaveopt xsavec xgetbv1 dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp
  bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass
  bogomips        : 7199.89
  clflush size    : 64
  cache_alignment : 64
  address sizes   : 39 bits physical, 48 bits virtual
  power management:
  
  processor       : 4
  vendor_id       : GenuineIntel
  cpu family      : 6
  model           : 158
  model name      : Intel(R) Core(TM) i7-7700 CPU @ 3.60GHz
  stepping        : 9
  microcode       : 0x84
  cpu MHz         : 4130.156
  cache size      : 8192 KB
  physical id     : 0
  siblings        : 8
  core id         : 0
  cpu cores       : 4
  apicid          : 1
  initial apicid  : 1
  fpu             : yes
  fpu_exception   : yes
  cpuid level     : 22
  wp              : yes
  flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch invpcid_single intel_pt ibrs ibpb stibp kaiser tpr_shadow vnmi flexpriority ept vpid fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpcid rtm mpx rdseed adx smap clflushopt xsaveopt xsavec xgetbv1 dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp
  bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass
  bogomips        : 7199.89
  clflush size    : 64
  cache_alignment : 64
  address sizes   : 39 bits physical, 48 bits virtual
  power management:
  
  processor       : 5
  vendor_id       : GenuineIntel
  cpu family      : 6
  model           : 158
  model name      : Intel(R) Core(TM) i7-7700 CPU @ 3.60GHz
  stepping        : 9
  microcode       : 0x84
  cpu MHz         : 4154.203
  cache size      : 8192 KB
  physical id     : 0
  siblings        : 8
  core id         : 1
  cpu cores       : 4
  apicid          : 3
  initial apicid  : 3
  fpu             : yes
  fpu_exception   : yes
  cpuid level     : 22
  wp              : yes
  flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch invpcid_single intel_pt ibrs ibpb stibp kaiser tpr_shadow vnmi flexpriority ept vpid fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpcid rtm mpx rdseed adx smap clflushopt xsaveopt xsavec xgetbv1 dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp
  bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass
  bogomips        : 7199.89
  clflush size    : 64
  cache_alignment : 64
  address sizes   : 39 bits physical, 48 bits virtual
  power management:
  
  processor       : 6
  vendor_id       : GenuineIntel
  cpu family      : 6
  model           : 158
  model name      : Intel(R) Core(TM) i7-7700 CPU @ 3.60GHz
  stepping        : 9
  microcode       : 0x84
  cpu MHz         : 4200.187
  cache size      : 8192 KB
  physical id     : 0
  siblings        : 8
  core id         : 2
  cpu cores       : 4
  apicid          : 5
  initial apicid  : 5
  fpu             : yes
  fpu_exception   : yes
  cpuid level     : 22
  wp              : yes
  flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch invpcid_single intel_pt ibrs ibpb stibp kaiser tpr_shadow vnmi flexpriority ept vpid fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpcid rtm mpx rdseed adx smap clflushopt xsaveopt xsavec xgetbv1 dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp
  bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass
  bogomips        : 7199.89
  clflush size    : 64
  cache_alignment : 64
  address sizes   : 39 bits physical, 48 bits virtual
  power management:
  
  processor       : 7
  vendor_id       : GenuineIntel
  cpu family      : 6
  model           : 158
  model name      : Intel(R) Core(TM) i7-7700 CPU @ 3.60GHz
  stepping        : 9
  microcode       : 0x84
  cpu MHz         : 4152.656
  cache size      : 8192 KB
  physical id     : 0
  siblings        : 8
  core id         : 3
  cpu cores       : 4
  apicid          : 7
  initial apicid  : 7
  fpu             : yes
  fpu_exception   : yes
  cpuid level     : 22
  wp              : yes
  flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch invpcid_single intel_pt ibrs ibpb stibp kaiser tpr_shadow vnmi flexpriority ept vpid fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpcid rtm mpx rdseed adx smap clflushopt xsaveopt xsavec xgetbv1 dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp
  bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass
  bogomips        : 7199.89
  clflush size    : 64
  cache_alignment : 64
  address sizes   : 39 bits physical, 48 bits virtual
  power management:
  ```