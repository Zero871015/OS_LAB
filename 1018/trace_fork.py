#!/usr/bin/env python
from bcc import BPF

prog = """
//BPF_TABLE("array", u32, u32, stats, 1);
BPF_ARRAY(stats, int, 1);
int hello_world(void *ctx) {
  int key = 0, value = 0, *val;
  val = stats.lookup_or_init(&key, &value);
  (*val)++;
  bpf_trace_printk("total fork syscall:%d\\n", *val);
  return 0;
}
"""

b = BPF(text=prog, debug=4)
b.attach_kprobe(event="__x64_sys_clone", fn_name="hello_world")
b.trace_print()
