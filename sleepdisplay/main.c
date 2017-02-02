#import <CoreFoundation/CoreFoundation.h>
#import <IOKit/IOKitLib.h>


int main(int argc, char *argv[])
{
	io_registry_entry_t displayWrangler = IORegistryEntryFromPath(kIOMasterPortDefault, "IOService:/IOResources/IODisplayWrangler");
	
	if (displayWrangler == MACH_PORT_NULL)
		return EXIT_FAILURE;
	
	kern_return_t error;
	
	error = IORegistryEntrySetCFProperty(displayWrangler, CFSTR("IORequestIdle"), kCFBooleanTrue);
	
	if (error != KERN_SUCCESS)
		return EXIT_FAILURE;
	
	error = IOObjectRelease(displayWrangler);
	
	if (error != KERN_SUCCESS)
		return EXIT_FAILURE;
	
	return EXIT_SUCCESS;
}

