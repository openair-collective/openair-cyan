Import("env")
proj_path = env["PROJECT_DIR"]
proj_path = proj_path.replace("\\", "\\\\")

macro_value = "\\\"" + proj_path + "\\\""

env.Append(CPPDEFINES=[("PROJECT_PATH", macro_value)])
