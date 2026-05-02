/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sfurst <sfurst@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/26 16:45:56 by sfurst           #+#    #+#              */
/*   Updated: 2026/04/30 21:52:15 by sfurst          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_count(char *s, int len)
{
	if (write(1, s, len) != len)
		return (-1);
	return (len);
}

int	ft_putchar_count(char c)
{
	return (ft_write_count(&c, 1));
}

int	ft_putnchar_count(char c, int n)
{
	int	i;
	int	count;
	int	written;

	i = 0;
	count = 0;
	while (i < n)
	{
		written = ft_putchar_count(c);
		if (written < 0)
			return (-1);
		count += written;
		i++;
	}
	return (count);
}

void	ft_format_init(t_format *f)
{
	f->minus = 0;
	f->zero = 0;
	f->hash = 0;
	f->plus = 0;
	f->space = 0;
	f->width = 0;
	f->precision = 0;
	f->has_precision = 0;
	f->type = conv_none;
}
gns3util via  v1 .25.7 on 󱗆 upmowmtz(feature / orchestration ~3)[∅]
✦ ❯ go run./ tools / scaffoldctl -
		chceck flag provided but not defined :
			-chceck Usage : scaffoldctl[flags]

																scaffoldctl bootstraps editable client
	and
	CLI scaffolding from YAML specs
			.

		Default spec discovery :.codegen
		/ scaffoldctl / packages/*.yaml
Default templates dir: tools/scaffoldctl/templates

Flags:
  -check
    	Validate specs, referenced models,
		and target method collisions without rendering a diff.
  -dry-run
    	Render and validate without writing files.
  -force
    	Allow overwriting scaffolded editable files.
  -list-cli
    	Print configured CLI commands and exit.
  -list-client
    	Print configured client methods and exit.
  -list-existing
    	Print existing ClientV2 methods in target files and exit.
  -list-packages
    	Print discovered scaffold packages and exit.
  -list-plan
    	Print the client and CLI generation plan.
  -list-sections
    	Print supported ClientV2 section keys and exit.
  -mode string
    	Generation mode: all, client, cli. (default "all")
  -no-pager
    	Use plain diff output instead of piping through delta.
  -only string
    	Comma-separated IDs to generate, for example: list_roles,get_role.
  -skip-existing
    	Skip configured client methods that already exist in the target file.
  -spec string
    	Path to the YAML scaffold spec.
  -spec-dir string
    	Directory containing scaffold specs for auto-discovery. (default ".codegen/scaffoldctl/packages")
  -templates-dir string
    	Directory containing Go templates. (default "tools/scaffoldctl/templates")
  -v	Enable verbose logging.
  -write
    	Write generated changes to target files and gofmt changed Go files.

Examples:
  scaffoldctl -dry-run
  scaffoldctl -dry-run -no-pager
  scaffoldctl -write -skip-existing
  scaffoldctl -check
  scaffoldctl -list-plan -skip-existing
  scaffoldctl -list-packages
  scaffoldctl -list-client
  scaffoldctl -list-cli
  scaffoldctl -spec-dir .codegen/scaffoldctl/packages -dry-run -v
  scaffoldctl -spec .codegen/scaffoldctl/packages/rbac.yaml
	-only list_roles,get_role
  scaffoldctl -list-sections
flag provided but not defined: -chceck
exit status 1

gns3util via  v1.25.7 on 󱗆 upmowmtz (feature/orchestration~3) [∅]
✦ ❯ go run ./tools/scaffoldctl -cceck
flag provided but not defined: -cceck
Usage: scaffoldctl [flags]

scaffoldctl bootstraps editable client and CLI scaffolding from YAML specs.

Default spec discovery: .codegen/scaffoldctl/packages/*.yaml
Default templates dir: tools/scaffoldctl/templates

Flags:
  -check
    	Validate specs, referenced models,
		and target method collisions without rendering a diff.
  -dry-run
    	Render and validate without writing files.
  -force
    	Allow overwriting scaffolded editable files.
  -list-cli
    	Print configured CLI commands and exit.
  -list-client
    	Print configured client methods and exit.
  -list-existing
    	Print existing ClientV2 methods in target files and exit.
  -list-packages
    	Print discovered scaffold packages and exit.
  -list-plan
    	Print the client and CLI generation plan.
  -list-sections
    	Print supported ClientV2 section keys and exit.
  -mode string
    	Generation mode: all, client, cli. (default "all")
  -no-pager
    	Use plain diff output instead of piping through delta.
  -only string
    	Comma-separated IDs to generate, for example: list_roles,get_role.
  -skip-existing
    	Skip configured client methods that already exist in the target file.
  -spec string
    	Path to the YAML scaffold spec.
  -spec-dir string
    	Directory containing scaffold specs for auto-discovery. (default ".codegen/scaffoldctl/packages")
  -templates-dir string
    	Directory containing Go templates. (default "tools/scaffoldctl/templates")
  -v	Enable verbose logging.
  -write
    	Write generated changes to target files and gofmt changed Go files.

Examples:
  scaffoldctl -dry-run
  scaffoldctl -dry-run -no-pager
  scaffoldctl -write -skip-existing
  scaffoldctl -check
  scaffoldctl -list-plan -skip-existing
  scaffoldctl -list-packages
  scaffoldctl -list-client
  scaffoldctl -list-cli
  scaffoldctl -spec-dir .codegen/scaffoldctl/packages -dry-run -v
  scaffoldctl -spec .codegen/scaffoldctl/packages/rbac.yaml
	-only list_roles,get_role
  scaffoldctl -list-sections
flag provided but not defined: -cceck
exit status 1

gns3util via  v1.25.7 on 󱗆 upmowmtz (feature/orchestration~3) [∅]
✦ ❯ go run ./tools/scaffoldctl -check
scaffoldctl found spec errors:
 
	- .codegen/scaffoldctl/packages/backups.yaml: client_methods.delete_backup: ClientV2.DeleteBackup already exists in pkg/api/client_v2.go:863
 
	- .codegen/scaffoldctl/packages/backups.yaml: client_methods.get_backup: ClientV2.GetBackup already exists in pkg/api/client_v2.go:881
 
	- .codegen/scaffoldctl/packages/backups.yaml: client_methods.init_backup_upload: ClientV2.InitBackupUpload already exists in pkg/api/client_v2.go:899
 
	- .codegen/scaffoldctl/packages/backups.yaml: client_methods.list_backups: ClientV2.ListBackups already exists in pkg/api/client_v2.go:919
 
	- .codegen/scaffoldctl/packages/backups.yaml: client_methods.update_backup: ClientV2.UpdateBackup already exists in pkg/api/client_v2.go:937
 
	- .codegen/scaffoldctl/packages/vm-images.yaml: client_methods.delete_vm_image: ClientV2.DeleteVMImage already exists in pkg/api/client_v2.go:959
 
	- .codegen/scaffoldctl/packages/vm-images.yaml: client_methods.get_vm_image: ClientV2.GetVMImage already exists in pkg/api/client_v2.go:977
 
	- .codegen/scaffoldctl/packages/vm-images.yaml: client_methods.init_vm_upload: ClientV2.InitVMUpload already exists in pkg/api/client_v2.go:995
 
	- .codegen/scaffoldctl/packages/vm-images.yaml: client_methods.list_vm_images: ClientV2.ListVMImages already exists in pkg/api/client_v2.go:1015
 
	- .codegen/scaffoldctl/packages/vm-images.yaml: client_methods.update_vm_image: ClientV2.UpdateVMImage already exists in pkg/api/client_v2.go:1033
exit status 1

