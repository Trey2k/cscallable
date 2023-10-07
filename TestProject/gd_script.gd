extends Node2D

func _ready() -> void:
	var example_ref_counted = ExampleRefCounted.new()
	var example_callable = example_ref_counted.get_exmaple_callable()
	example_callable.call()
