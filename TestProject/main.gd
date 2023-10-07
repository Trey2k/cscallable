extends Node2D

var cs_scene = preload("res://c_sharp.tscn").instantiate()
var gds_scene = preload("res://gd_script.tscn").instantiate()

func _ready() -> void:
	print("Running GDScript Example")
	print("------------------------")
	add_child(gds_scene)
	print("------------------------")
	print("Running C# Example")
	print("------------------------")
	add_child(cs_scene)
	print("------------------------")

func _process(delta: float) -> void:
	get_tree().quit()
