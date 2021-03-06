#ifndef MEMCTL_CLI__CLI_H_
#define MEMCTL_CLI__CLI_H_

#include "command.h"
#include "disassemble.h"

#include "memctl/kernel_call.h"

bool default_action(void);

bool i_command(void);
bool r_command(kaddr_t address, size_t length, bool force, bool physical, size_t width,
		size_t access, bool dump);
bool rb_command(kaddr_t address, size_t length, bool force, bool physical, size_t access);
#if MEMCTL_DISASSEMBLY
bool ri_command(kaddr_t address, size_t length, bool force, bool physical, size_t access);
bool rif_command(const char *function, const char *kext, bool force, size_t access);
#endif
bool rs_command(kaddr_t address, size_t length, bool force, bool physical, size_t access);
bool w_command(kaddr_t address, kword_t value, bool force, bool physical, size_t width,
		size_t access);
bool wd_command(kaddr_t address, const void *data, size_t length, bool force, bool physical,
		size_t access);
bool ws_command(kaddr_t address, const char *string, bool force, bool physical, size_t access);
bool f_command(kaddr_t start, kaddr_t end, kword_t value, size_t width, bool physical, bool heap,
		size_t access, size_t alignment);
bool fpr_command(pid_t pid);
bool fc_command(kaddr_t start, kaddr_t end, const char *classname, const char *bundle_id,
		size_t access);
bool kc_command(kaddr_t function, size_t width, size_t argument_count,
		struct kernel_call_argument *arguments);
bool kcv_command(size_t width, size_t vmethod_index, size_t argument_count,
		struct kernel_call_argument *arguments);
bool lc_command(kaddr_t address);
bool cm_command(const char *classname, const char *bundle_id);
bool cz_command(const char *classname, const char *bundle_id);
bool kp_command(kaddr_t address);
bool kpm_command(kaddr_t start, kaddr_t end);
bool zs_command(kaddr_t address);
bool pca_command(kaddr_t address, bool is_virtual);
bool vt_command(const char *classname, const char *bundle_id);
bool vtl_command(kaddr_t address);
bool vm_command(kaddr_t address, unsigned depth);
bool vmm_command(kaddr_t start, kaddr_t end, unsigned depth);
bool vma_command(size_t size);
bool vmd_command(kaddr_t address, size_t size);
bool vmp_command(kaddr_t address, size_t length, int prot);
bool ks_command(kaddr_t address, bool unslide);
bool a_command(const char *symbol, const char *kext);
bool ap_command(kaddr_t address, bool unpermute);
bool s_command(kaddr_t address);
bool kcd_command(const char *kernelcache, const char *output);
bool root_command(void);
#if MEMCTL_REPL
bool quit_command(void);
#endif

#endif
