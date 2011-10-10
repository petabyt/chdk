depend: depend-recursive $(OBJS:.o=.d)

#ifneq ($(strip $(OBJS)),)
#-include $(OBJS:%.o=.dep/%.d)
#endif


# Define empty recipes for all the included makefiles (including this one)
# This stops gmake from attempting to see if the makefiles need to be rebuilt
$(topdir)bottom.inc: ;
