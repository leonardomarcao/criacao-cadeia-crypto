::this will avoid that the credentials of finance are saved
NET USE \\fin\\ADM1$ /DELETE ::for delete fin\adm1$
NET USE \\FIN\\IPC$ /DELETE ::for delete fin\ipc$
NET USE \\FIN /DELETE ::for delete fin
cmdkey /delete:fin ::for delete all credentials of financeiro