Ex.: ./pipex infile cmd1 cmd2 outfile pipe() 
| +--- fork() 
| +--- child1 [cmd1] 
| +-- dup2(fd_infile, STDIN)) 
| +-- dup2(pipe[1], STDOUT) 
| +-- close(pipe[0]) 
| +-- close(pipe[1]) 
| +-- ft_split the command options 
| and find the correct path 
| +-- execve(cmd1_path, options, envp) 
| +--- child2 [cmd2] 
| +-- dup2(pipe[0], STDIN) 
| +-- dup2(fd_outfile, STDOUT) 
| +-- close(pipe[0]) 
| +-- close(pipe[1]) 
| +-- ft_split the command options | and find the correct path 
| +-- execve(cmd2_path, options, envp) 
| +--- parent +-- close(pipe[0]) +-- close(pipe[1]) 
  +-- close(fd_infile) 
  +-- close(fd_outfile) +-- waitpid(pid1, status, 0) +-- waitpid(pid2, status, 0)
